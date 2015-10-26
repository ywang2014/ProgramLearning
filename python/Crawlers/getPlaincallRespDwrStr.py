# -*- coding: utf-8 -*-

'''
解析部分代码
'''

def getPlaincallRespDwrStr(c0ScriptName, c0MethodName, c0Param0, c0Param1, c0Param2):
    """
        get FeelingsBeanNew response DWR string
    """
     
    #typ1:
    # http://api.blog.163.com/againinput4/dwr/call/plaincall/BlogBeanNew.getComments.dwr
    # for: http://againinput4.blog.163.com/blog/static/172799491201010159650483/
    # [paras]
    # callCount=1
    # scriptSessionId=${scriptSessionId}187
    # c0-scriptName=BlogBeanNew
    # c0-methodName=getComments
    # c0-id=0
    # c0-param0=string:fks_094067082083086070082083080095085081083068093095082074085
    # c0-param1=number:1
    # c0-param2=number:0
    # batchId=728048
    #http://api.blog.163.com/againinput4/dwr/call/plaincall/BlogBeanNew.getComments.dwr?&callCount=1&scriptSessionId=${scriptSessionId}187&c0-scriptName=BlogBeanNew&c0-methodName=getComments&c0-id=0&c0-param0=string:fks_094067082083086070082083080095085081083068093095082074085&c0-param1=number:1&c0-param2=number:0&batchId=728048
     
     
    #type2:
    # callCount=1
    # scriptSessionId=${scriptSessionId}187
    # c0-scriptName=FeelingsBeanNew
    # c0-methodName=getRecentFeelingsComment
    # c0-id=0
    # c0-param0=string:134875456
    # c0-param1=number:1
    # c0-param2=number:0
    # batchId=705438
     
    #type3:
    # callCount=1
    # scriptSessionId=${scriptSessionId}187
    # c0-scriptName=FeelingsBeanNew
    # c0-methodName=getRecentFeelingCards
    # c0-id=0
    # c0-param0=number:186541395
    # c0-param1=number:0
    # c0-param2=number:20
    # batchId=292545
 
    logging.debug("get FeelingsBeanNew reponse DWR string for c0MethodName=%s, c0Param0=%s, c0Param1=%s, c0Param2=%s", c0MethodName, c0Param0, c0Param1, c0Param2);
     
    postDict = {
        'callCount'     :   '1',
        'scriptSessionId':  '${scriptSessionId}187',
        'c0-scriptName' :   c0ScriptName, #BlogBeanNew/FeelingsBeanNew
        'c0-methodName' :   c0MethodName, #getComments/getRecentFeelingsComment/getRecentFeelingCards
        'c0-id'         :   '0',
        'c0-param0'     :   c0Param0,
        'c0-param1'     :   c0Param1,
        'c0-param2'     :   c0Param2,
        'batchId'       :   '1', # should random generate number?
    };
    #http://api.blog.163.com/againinput4/dwr/call/plaincall/BlogBeanNew.getComments.dwr
    #http://api.blog.163.com/ni_chen/dwr/call/plaincall/FeelingsBeanNew.getRecentFeelingsComment.dwr
    #http://api.blog.163.com/ni_chen/dwr/call/plaincall/FeelingsBeanNew.getRecentFeelingCards.dwr
    plaincallDwrUrl = gConst['blogApi163'] + '/' + gVal['blogUser'] + '/' + "dwr/call/plaincall/" + c0ScriptName + "." + c0MethodName + ".dwr";
    logging.debug("plaincallDwrUrl=%s", plaincallDwrUrl);
 
    #Referer    http://api.blog.163.com/crossdomain.html?t=20100205
    headerDict = {
        'Referer'       :   "http://api.blog.163.com/crossdomain.html?t=20100205",
        'Content-Type'  :   "text/plain",
    };
    plaincallRespDwrStr = crifanLib.getUrlRespHtml(plaincallDwrUrl, postDict=postDict, headerDict=headerDict, postDataDelimiter='\r\n');
    logging.debug("plaincallRespDwrStr=%s", plaincallRespDwrStr);
 
    return plaincallRespDwrStr;
 
def fetchComments_feelingCard():
    """
        Get feeling card items, to use as comments
    """
 
    totalCmtDictList = [];
    totalMainCmtDictList = [];
    totalSubCmtDictList = [];
     
    # init before loop
    needGetMore = True;
    startIdx = 0;
    startNum = 1;
    onceGetNum = 1000; # get 1000 items once
     
    try :
        while needGetMore :
            # get resopnse dwr string
             
            # callCount=1
            # scriptSessionId=${scriptSessionId}187
            # c0-scriptName=FeelingsBeanNew
            # c0-methodName=getRecentFeelingCards
            # c0-id=0
            # c0-param0=number:186541395
            # c0-param1=number:0
            # c0-param2=number:20
            # batchId=292545
            getRecentFeelingCardsRespDwrStr = getPlaincallRespDwrStr(   "FeelingsBeanNew",
                                                                        "getRecentFeelingCards",
                                                                        "number:" + str(gVal['userId']),
                                                                        "number:" + str(startIdx),
                                                                        "number:" + str(onceGetNum));
            logging.debug("getRecentFeelingCardsRespDwrStr=%s", getRecentFeelingCardsRespDwrStr);
            curMainCmtDictList = parseMainCmtDwrStrToMainCmtDictList(getRecentFeelingCardsRespDwrStr);
            totalMainCmtDictList.extend(curMainCmtDictList);
             
            curGotMainCmtNum = len(curMainCmtDictList);
            if(curGotMainCmtNum < onceGetNum):
                #has got all comment, so quit
                needGetMore = False;
                logging.debug("Request %d comments, but only response %d comments, so no more comments, has got all comments", onceGetNum, curGotMainCmtNum);
 
        #add main comment dict list into total comment dict list
        logging.debug("Total got %d main comments dict", len(totalMainCmtDictList));
        totalCmtDictList.extend(totalMainCmtDictList);
        logging.debug("Total comments %d", len(totalCmtDictList));
         
        #after get all main comment dict, then try to find the sub comments
        for eachMainCmtDict in totalMainCmtDictList:
            #logging.info("eachMainCmtDict=%s", eachMainCmtDict);
            mainCommentCount = eachMainCmtDict['mainCommentCount'];
            #logging.info("mainCommentCount=%s", mainCommentCount);
            mainCommentCountInt = int(mainCommentCount);
            #logging.info("mainCommentCountInt=%d", mainCommentCountInt);
            if(mainCommentCountInt > 0):
                #has sub comment
                logging.debug("[%d] main comment has sub %d comments", eachMainCmtDict['curCmtIdx'], mainCommentCountInt);
                #1. get sub comment dwr string
                subCmtDwrStr = getFeelingCardSubCmtDwrStr(eachMainCmtDict['id']);
                #2. parse sub comment dwr string to sub comment dict
                curSubCmtDictList = parseSubCmtDwrStrToSubCmtDictList(subCmtDwrStr);
                totalSubCmtDictList.extend(curSubCmtDictList);
         
        #do some update for sub comment
        logging.debug("Total got %d sub comment dict", len(totalSubCmtDictList));
        if(totalSubCmtDictList):
            #update sub comment index
            subCmtStartIdx = len(totalMainCmtDictList);
            logging.debug("subCmtStartIdx=%d", subCmtStartIdx);
            for idx,eachSubCmtDict in enumerate(totalSubCmtDictList):
                eachSubCmtDict['curCmtIdx'] = subCmtStartIdx + idx;
                eachSubCmtDict['curCmtNum'] = eachSubCmtDict['curCmtIdx'] + 1;
             
            logging.debug("done for update sub comment index");
            #update sub comment's parent relation
            for idx,eachSubCmtDict in enumerate(totalSubCmtDictList):
                subCmtParentId = eachSubCmtDict['cardId'];
                for eachMainCmtDict in totalMainCmtDictList:
                    mainCmtId = eachMainCmtDict['id'];
                    if(subCmtParentId == mainCmtId):
                        logging.debug("sub cmt id=%s 's parent's id=%s, parent curCmtNum=%d", eachSubCmtDict['id'], mainCmtId, eachMainCmtDict['curCmtNum']);
                        eachSubCmtDict['parentCmtNum'] = eachMainCmtDict['curCmtNum'];
                 
                #update sub comment's parent whose within sub comment list
                #s0.replyComId="-1";
                #s3.replyComId="72175292"
                curSubCmtReplyComId = eachSubCmtDict['replyComId']; #
                for singleSubCmtDict in totalSubCmtDictList:
                    subCmtId = singleSubCmtDict['id'];
                    subCmtCurCmtNum = singleSubCmtDict['curCmtNum'];
                    if(curSubCmtReplyComId == subCmtId):
                        logging.debug("sub cmt id=%s 's replyComId=%s, find correspoinding parent (sub) comment, whose curCmtNum=%d", subCmtId, curSubCmtReplyComId, subCmtCurCmtNum);
                        eachSubCmtDict['parentCmtNum'] = subCmtCurCmtNum;
                 
            logging.debug("done for update sub comment's parent relation");
            totalCmtDictList.extend(totalSubCmtDictList);
    except :
        logging.debug("Fail for fetch the feeling card (index=[%d-%d]) for %s ", startIdx, startIdx + onceGetNum - 1, url);
 
    return totalCmtDictList;
 
def getFeelingCardSubCmtDwrStr(subCmtId):
    """
        input sub comment id, return sub comment response dwr string
    """
    # callCount=1
    # scriptSessionId=${scriptSessionId}187
    # c0-scriptName=FeelingsBeanNew
    # c0-methodName=getRecentFeelingsComment
    # c0-id=0
    # c0-param0=string:134875456
    # c0-param1=number:1
    # c0-param2=number:0
    # batchId=705438
     
    logging.debug("get sub comment for %s", subCmtId);
 
    getRecentFeelingsCommentRespDwrStr = getPlaincallRespDwrStr(    "FeelingsBeanNew",
                                                                    "getRecentFeelingsComment",
                                                                    "string:" + str(subCmtId),
                                                                    "number:1",
                                                                    "number:0");
    logging.debug("getRecentFeelingsCommentRespDwrStr=%s", getRecentFeelingsCommentRespDwrStr);
 
    return getRecentFeelingsCommentRespDwrStr;
 
def parseSingleDwrStrToCmtDict(singleCmtDwrStr):
    """
        parse single comment dwr string, main comment or sub comment, to comment dict
    """
    logging.debug("singleCmtDwrStr=%s", singleCmtDwrStr);
 
    #init values
    curCmtDict = {};
     
    singleMainCmtDict = {
        'curCmtIdx'         : 0,
        'curCmtNum'         : 0,
        'parentCmtNum'      : 0,
        'isSubComment'      : False,
 
        'commentCount'      : "",
        'mainCommentCount'  : "",
        'moodType'          : "",
        'userAvatar'        : "",
        'userAvatarUrl'     : "",
        'userName'          : "",
        'userNickname'      : "",
        #common part
        'content'           : "",
        'id'                : "",
        'moveFrom'          : "",
        'publishTime'       : "",
        'synchMiniBlog'     : "",
        'userId'            : "",
    };
     
    singleSubCmtDict = {
        'curCmtIdx'         : 0,
        'curCmtNum'         : 0,
        'parentCmtNum'      : 0,
        'isSubComment'      : True,
         
        'cardId'            : "", # is parent ID
        'ip'                : "",
        'ipName'            : "",
        'lastUpdateTime'    : "",
        'mainComId'         : "",
        'popup'             : "",
        'publisherAvatar'   : "",
        'publisherAvatarUrl': "",
        'publisherId'       : "",
        'publisherName'     : "",
        'publisherNickname' : "",
        'publisherUrl'      : "",
        'replyComId'        : "",
        'replyToUserId'     : "",
        'replyToUserName'   : "",
        'replyToUserNick'   : "",
        'spam'              : "",
        'subComments'       : "",
        'valid'             : "",
        #common part
        'content'           : "",
        'id'                : "",
        'moveFrom'          : "",
        'publishTime'       : "",
        'synchMiniBlog'     : "",
        'userId'            : "",
    };
 
    #1. check is main comment or sub comment
    #start with sN.cardId=, is sub comment
    foundCardId = re.search("^s\d+\.cardId=", singleCmtDwrStr);
    if(foundCardId):
        curCmtDict = singleSubCmtDict;
        curCmtDict['isSubComment'] = True;
        logging.debug("------- is sub comments");
    else:
        curCmtDict = singleMainCmtDict;
        curCmtDict['isSubComment'] = False;
        logging.debug("======= is main comments");
 
    #2. process common key and value
 
    #common key and value
 
    #fisrt get the comment index
    #main comment:
    #s0.content="\u7EC8\u4E8E\u6709iphone\u7248\u7684\u4E86";s0.id="
    #sub comment:
    #s0.content="\u81EA\u5DF1\u4E70\u70B9\u6C34\u679C\u5403\u3002";s0.id="
    #s0.commentCount=0;s0.content="\u7EC8\u4E8E\u6709iphone\u7248\u7684\u4E86";s0.id="148749270";s0.mainCommentCount=0;s0.moodType=0;s0.moveFrom="iphone";s0.publishTime=1374626867596;s0.synchMiniBlog=-1;s0.userAvatar=0;s0.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.userId=186541395;s0.userName="ni_chen";s0.userNickname="Neysa";
     
    foundCurCmtIdx = re.search(r's(?P<curCmtIdx>\d+)\.content=".+?";s\1\.id="', singleCmtDwrStr);
    logging.debug("foundCurCmtIdx=%s", foundCurCmtIdx);
    curCmtIdx = foundCurCmtIdx.group("curCmtIdx");
    curCmtIdx = int(curCmtIdx);
    logging.debug("curCmtIdx=%d", curCmtIdx);
    if(not curCmtDict['isSubComment']):
        #only add for main comment
        #later, will update sub comment curCmtIdx and curCmtNum
        curCmtDict['curCmtIdx'] = curCmtIdx;
        curCmtDict['curCmtNum'] = curCmtIdx + 1;
 
    #init some common values
    strSn = "s" + str(curCmtIdx);
     
    #content
    #s0.content="\u7EC8\u4E8E\u6709iphone\u7248\u7684\u4E86";s0.id="
    foundContent = re.search(strSn + '\.content=(?P<content>.+?);' + strSn + '\.id="', singleCmtDwrStr);
    content = foundContent.group("content");
    content = content.decode("unicode-escape");
    curCmtDict['content'] = content;
    logging.debug("content=%s", content);
 
    #id
    #s0.id="148749270";
    foundId = re.search(strSn + '\.id="(?P<id>\d+)";', singleCmtDwrStr);
    id = foundId.group("id");
    curCmtDict['id'] = id;
    logging.debug("id=%s", id);
 
    #moveFrom
    #s0.moveFrom="iphone";
    #s2.moveFrom=null;
    #s8.moveFrom="wap";
    #s699.moveFrom="";
    foundMoveFrom = re.search(strSn + '\.moveFrom="?(?P<moveFrom>[^"]*?)"?;', singleCmtDwrStr);
    moveFrom = foundMoveFrom.group("moveFrom");
    curCmtDict['moveFrom'] = moveFrom;
    logging.debug("moveFrom=%s", moveFrom);
 
    #publishTime
    #s0.publishTime=1374626867596;
    foundPublishTime = re.search(strSn + '\.publishTime=(?P<publishTime>\d+);', singleCmtDwrStr);
    publishTime = foundPublishTime.group("publishTime");
    curCmtDict['publishTime'] = publishTime;
    logging.debug("publishTime=%s", publishTime);
 
    #synchMiniBlog
    #s0.synchMiniBlog=-1;
    #in sub comment:
    #s0.synchMiniBlog=false;
    foundSynchMiniBlog = re.search(strSn + '\.synchMiniBlog=(?P<synchMiniBlog>.+?);', singleCmtDwrStr);
    synchMiniBlog = foundSynchMiniBlog.group("synchMiniBlog");
    curCmtDict['synchMiniBlog'] = synchMiniBlog;
    logging.debug("synchMiniBlog=%s", synchMiniBlog);
 
    #userId
    #s0.userId=186541395;
    foundUserId = re.search(strSn + '\.userId=(?P<userId>\d+);', singleCmtDwrStr);
    userId = foundUserId.group("userId");
    curCmtDict['userId'] = userId;
    logging.debug("userId=%s", userId);
 
    #3. process different key and value
     
    if(curCmtDict['isSubComment']):
        #process sub comment remaing field
 
     
        #sub comment dwr string:
        
        #sample 1: #s0.cardId="134875456";s0.content="\u81EA\u5DF1\u4E70\u70B9\u6C34\u679C\u5403\u3002";s0.id="73300019";s0.ip="203.234.215.66";s0.ipName=null;s0.lastUpdateTime=1351380367156;s0.mainComId="-1";s0.moveFrom=null;s0.popup=false;s0.publishTime=1351380367155;s0.publisherAvatar=0;s0.publisherAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.publisherId=55976067;s0.publisherName="chenlin198412@126";s0.publisherNickname="Lynn";s0.publisherUrl=null;s0.replyComId="-1";s0.replyToUserId=186541395;s0.replyToUserName="ni_chen";s0.replyToUserNick="Neysa";s0.spam=0;s0.subComments=s1;s0.synchMiniBlog=false;s0.userId=186541395;s0.valid=0;
 
        #sample 2:
        # s0.cardId="133211376";s0.content="\u4ECE\u9AD8\u4E2D\u5C31\u5F00\u59CB\u7684\u5417\uFF1F\u597D\u597D\u53BB\u533B\u9662\u68C0\u67E5\u4E00\u4E0B\u5427\uFF0C\u73B0\u5728\u6709\u75C5\u4E00\u5B9A\u4E0D\u8981\u62D6\u7740\uFF0C\u8981\u4E0D\u5C0F\u75C5\u4E5F\u4F1A\u53D8\u6210\u5927\u75C5\uFF0C\u5230\u65F6\u53EF\u6CA1\u6709\u540E\u6094\u836F\u5403\u3002";s0.id="72192291";s0.ip="115.170.58.191";s0.ipName=null;s0.lastUpdateTime=1348561288469;s0.mainComId="-1";s0.moveFrom=null;s0.popup=false;s0.publishTime=1348468815327;s0.publisherAvatar=0;s0.publisherAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.publisherId=26959367;s0.publisherName="chenyuanyuan0913";s0.publisherNickname="\u6C89\u7F18\u6E90";s0.publisherUrl=null;s0.replyComId="-1";s0.replyToUserId=186541395;s0.replyToUserName="ni_chen";s0.replyToUserNick="Neysa";s0.spam=0;s0.subComments=s1;s0.synchMiniBlog=false;s0.userId=186541395;s0.valid=0;
 
        # s1[0]=s2;s1[1]=s3;s1[2]=s4;
 
        # s2.cardId="133211376";s2.content="\u4E00\u76F4\u60F3\u67E5\uFF0C\u4F46\u662F\u6CA1\u6709\u533B\u7597\u4FDD\u9669<img src=\"http://b.bst.126.net/common/portrait/face/preview/face2.gif\"  >\u3002\u6211\u5F97\u5148\u95EE\u6E05\u695A\u4E00\u4E0B";s2.id="72175292";s2.ip="147.46.115.126";s2.ipName=null;s2.lastUpdateTime=0;s2.mainComId="72192291";s2.moveFrom=null;s2.popup=false;s2.publishTime=1348471820683;s2.publisherAvatar=0;s2.publisherAvatarUrl=null;s2.publisherId=186541395;s2.publisherName="ni_chen";s2.publisherNickname="Neysa";s2.publisherUrl=null;s2.replyComId="72192291";s2.replyToUserId=26959367;s2.replyToUserName="chenyuanyuan0913";s2.replyToUserNick="\u6C89\u7F18\u6E90";s2.spam=0;s2.subComments=s5;s2.synchMiniBlog=false;s2.userId=186541395;s2.valid=0;
        #s3.cardId="133211376";s3.content="\u522B\u62D6\u5EF6\uFF0C\u505A\u4E2A\u68C0\u67E5\u82B1\u4E0D\u4E86\u591A\u5C11\u94B1\u7684\uFF0C\u522B\u5230\u65F6\u771F\u751F\u75C5\u4E86\uFF0C\u90A3\u53EF\u82B1\u5F97\u4E0D\u662F\u4E00\u70B9\u534A\u70B9\u7684\u3002\u6709\u65F6\u95F4\u4E86\u5C31\u8D76\u7D27\u53BB\uFF0C\u4E00\u5B9A\u8981\u53BB\u554A\uFF0C\u6CA1\u4EC0\u4E48\u4E8B\u5C31\u653E\u5FC3\u4E86\u3002\u8BB0\u5F97\u6211\u4EEC\u5BBF\u820D\u90A3\u4E2A\u5C0F\u59D1\u5A18\u5417\uFF0C\u90A3\u53EF\u662F\u771F\u5B9E\u7684\u6559\u8BAD\u554A";s3.id="72227357";s3.ip="115.170.26.179";s3.ipName=null;s3.lastUpdateTime=0;s3.mainComId="72192291";s3.moveFrom=null;s3.popup=false;s3.publishTime=1348560697833;s3.publisherAvatar=0;s3.publisherAvatarUrl=null;s3.publisherId=26959367;s3.publisherName="chenyuanyuan0913";s3.publisherNickname="\u6C89\u7F18\u6E90";s3.publisherUrl=null;s3.replyComId="72175292";s3.replyToUserId=186541395;s3.replyToUserName="ni_chen";s3.replyToUserNick="Neysa";s3.spam=0;s3.subComments=s6;s3.synchMiniBlog=false;s3.userId=186541395;s3.valid=0;
 
        # s4.cardId="133211376";s4.content="\u55EF\uFF0C\u77E5\u9053\u5566<img src=\"http://b.bst.126.net/common/portrait/face/preview/face47.gif\"  >";s4.id="72206314";s4.ip="147.46.115.126";s4.ipName=null;s4.lastUpdateTime=0;s4.mainComId="72192291";s4.moveFrom=null;s4.popup=false;s4.publishTime=1348561288458;s4.publisherAvatar=0;s4.publisherAvatarUrl=null;s4.publisherId=186541395;s4.publisherName="ni_chen";s4.publisherNickname="Neysa";s4.publisherUrl=null;s4.replyComId="72227357";s4.replyToUserId=26959367;s4.replyToUserName="chenyuanyuan0913";s4.replyToUserNick="\u6C89\u7F18\u6E90";s4.spam=0;s4.subComments=s7;s4.synchMiniBlog=false;s4.userId=186541395;s4.valid=0;
         
        #sample 3:
        #s0.cardId="131435017";s0.content="\u54C8\u54C8\uFF0C\u4FFA\u662F\u7B14\u8FF9\u63A7";s0.id="70788610";s0.ip=null;s0.ipName=null;s0.lastUpdateTime=1344839449690;s0.mainComId="-1";s0.moveFrom="iphone";s0.popup=false;s0.publishTime=1344839449690;s0.publisherAvatar=0;s0.publisherAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.publisherId=186541395;s0.publisherName="ni_chen";s0.publisherNickname="Neysa";s0.publisherUrl=null;s0.replyComId="-1";s0.replyToUserId=0;s0.replyToUserName="";s0.replyToUserNick="";s0.spam=0;s0.subComments=s1;s0.synchMiniBlog=false;s0.userId=186541395;s0.valid=0;
         
        #sample 4:
        #s0.cardId="131435017";s0.content="\u54C8\u54C8\uFF0C\u4FFA\u662F\u7B14\u8FF9\u63A7";s0.id="70788610";s0.ip=null;s0.ipName=null;s0.lastUpdateTime=1344839449690;s0.mainComId="-1";s0.moveFrom="iphone";s0.popup=false;s0.publishTime=1344839449690;s0.publisherAvatar=0;s0.publisherAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.publisherId=186541395;s0.publisherName="ni_chen";s0.publisherNickname="Neysa";s0.publisherUrl=null;s0.replyComId="-1";s0.replyToUserId=0;s0.replyToUserName="";s0.replyToUserNick="";s0.spam=0;s0.subComments=s1;s0.synchMiniBlog=false;s0.userId=186541395;s0.valid=0;
         
        #sample 5:
        #s0.cardId="111039854";s0.content="\u65B0\u53D1\u578B\u771F\u5F97\u5F88\u6F02\u4EAE\u554A\u2026\u2026\u53EF\u4EE5\u4F20\u4E00\u7EC4\u7167\u7247\u8BA9\u59D0\u59D0\u770B\u770B\u5417\uFF1F";s0.id="58333672";s0.ip=null;s0.ipName=null;s0.lastUpdateTime=1251121541764;s0.mainComId="-1";s0.moveFrom="";s0.popup=false;s0.publishTime=1251121541764;s0.publisherAvatar=0;s0.publisherAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.publisherId=26959367;s0.publisherName="chenyuanyuan0913";s0.publisherNickname="\u6C89\u7F18\u6E90";s0.publisherUrl=null;s0.replyComId="-1";s0.replyToUserId=0;s0.replyToUserName=null;s0.replyToUserNick=null;s0.spam=0;s0.subComments=s1;s0.synchMiniBlog=false;s0.userId=186541395;s0.valid=0;
         
         
        #cardId
        #s0.cardId="134875456";
        foundCardId = re.search(strSn + '\.cardId="?(?P<cardId>.*?)"?;', singleCmtDwrStr);
        cardId = foundCardId.group("cardId");
        curCmtDict['cardId'] = cardId;
        logging.debug("cardId=%s", cardId);
 
        #ip
        #s0.ip="203.234.215.66";
        #s0.ip=null;
        foundIp = re.search(strSn + '\.ip="?(?P<ip>.*?)"?;', singleCmtDwrStr);
        ip = foundIp.group("ip");
        if(not re.search("\d+\.\d+\.\d+\.\d+", ip)):
            ip = "";
        curCmtDict['ip'] = ip;
        logging.debug("ip=%s", ip);
 
        #ipName
        #s0.ipName=null;
        foundIpName = re.search(strSn + '\.ipName=(?P<ipName>.+?);', singleCmtDwrStr);
        ipName = foundIpName.group("ipName");
        curCmtDict['ipName'] = ipName;
        logging.debug("ipName=%s", ipName);
 
        #lastUpdateTime
        #s0.lastUpdateTime=1351380367156;
        foundLastUpdateTime = re.search(strSn + '\.lastUpdateTime=(?P<lastUpdateTime>\d+);', singleCmtDwrStr);
        lastUpdateTime = foundLastUpdateTime.group("lastUpdateTime");
        curCmtDict['lastUpdateTime'] = lastUpdateTime;
        logging.debug("lastUpdateTime=%s", lastUpdateTime);
 
        #mainComId
        #s0.mainComId="-1";
        foundMainComId = re.search(strSn + '\.mainComId="?(?P<mainComId>.*?)"?;', singleCmtDwrStr);
        mainComId = foundMainComId.group("mainComId");
        curCmtDict['mainComId'] = mainComId;
        logging.debug("mainComId=%s", mainComId);
 
        #popup
        #s0.popup=false;
        foundPopup = re.search(strSn + '\.popup=(?P<popup>.+?);', singleCmtDwrStr);
        popup = foundPopup.group("popup");
        curCmtDict['popup'] = popup;
        logging.debug("popup=%s", popup);
 
        #publisherAvatar
        #s0.publisherAvatar=0;
        foundPublisherAvatar = re.search(strSn + '\.publisherAvatar=(?P<publisherAvatar>\d+);', singleCmtDwrStr);
        publisherAvatar = foundPublisherAvatar.group("publisherAvatar");
        curCmtDict['publisherAvatar'] = publisherAvatar;
        logging.debug("publisherAvatar=%s", publisherAvatar);
 
        #publisherAvatarUrl
        #s0.publisherAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";
        #s2.publisherAvatarUrl=null;
        foundPublisherAvatarUrl = re.search(strSn + '\.publisherAvatarUrl="?(?P<publisherAvatarUrl>.*?)"?;', singleCmtDwrStr);
        publisherAvatarUrl = foundPublisherAvatarUrl.group("publisherAvatarUrl");
        curCmtDict['publisherAvatarUrl'] = publisherAvatarUrl;
        logging.debug("publisherAvatarUrl=%s", publisherAvatarUrl);
 
        #publisherId
        #s0.publisherId=55976067;
        foundPublisherId = re.search(strSn + '\.publisherId=(?P<publisherId>\d+);', singleCmtDwrStr);
        publisherId = foundPublisherId.group("publisherId");
        curCmtDict['publisherId'] = publisherId;
        logging.debug("publisherId=%s", publisherId);
 
        #publisherName
        #s0.publisherName="chenlin198412@126";
        foundPublisherName = re.search(strSn + '\.publisherName="?(?P<publisherName>.*?)"?;', singleCmtDwrStr);
        publisherName = foundPublisherName.group("publisherName");
        curCmtDict['publisherName'] = publisherName;
        logging.debug("publisherName=%s", publisherName);
 
        #publisherNickname
        #s0.publisherNickname="Lynn";
        foundPublisherNickname = re.search(strSn + '\.publisherNickname="?(?P<publisherNickname>.*?)"?;', singleCmtDwrStr);
        publisherNickname = foundPublisherNickname.group("publisherNickname");
        publisherNicknameUni = publisherNickname.decode('unicode-escape');
        curCmtDict['publisherNickname'] = publisherNicknameUni;
        logging.debug("publisherNickname=%s", publisherNickname);
 
        #publisherUrl
        #s0.publisherUrl=null;
        foundPublisherUrl = re.search(strSn + '\.publisherUrl="?(?P<publisherUrl>.*?)"?;', singleCmtDwrStr);
        publisherUrl = foundPublisherUrl.group("publisherUrl");
        curCmtDict['publisherUrl'] = publisherUrl;
        logging.debug("publisherUrl=%s", publisherUrl);
 
        #replyComId
        #s0.replyComId="-1";
        foundReplyComId = re.search(strSn + '\.replyComId="?(?P<replyComId>.*?)"?;', singleCmtDwrStr);
        replyComId = foundReplyComId.group("replyComId");
        curCmtDict['replyComId'] = replyComId;
        logging.debug("replyComId=%s", replyComId);
 
        #replyToUserId
        #s0.replyToUserId=186541395;
        foundReplyToUserId = re.search(strSn + '\.replyToUserId=(?P<replyToUserId>\d+);', singleCmtDwrStr);
        replyToUserId = foundReplyToUserId.group("replyToUserId");
        curCmtDict['replyToUserId'] = replyToUserId;
        logging.debug("replyToUserId=%s", replyToUserId);
 
        #replyToUserName
        #s0.replyToUserName="ni_chen";
        #s0.replyToUserName="";
        #s0.replyToUserName=null;
        foundReplyToUserName = re.search(strSn + '\.replyToUserName="?(?P<replyToUserName>.*?)"?;', singleCmtDwrStr);
        replyToUserName = foundReplyToUserName.group("replyToUserName");
        curCmtDict['replyToUserName'] = replyToUserName;
        logging.debug("replyToUserName=%s", replyToUserName);
 
        #replyToUserNick
        #s0.replyToUserNick="Neysa";
        #s0.replyToUserNick=null;
        foundReplyToUserNick = re.search(strSn + '\.replyToUserNick="?(?P<replyToUserNick>.*?)"?;', singleCmtDwrStr);
        replyToUserNick = foundReplyToUserNick.group("replyToUserNick");
        curCmtDict['replyToUserNick'] = replyToUserNick;
        logging.debug("replyToUserNick=%s", replyToUserNick);
 
        #spam
        #s0.spam=0;
        foundSpam = re.search(strSn + '\.spam=(?P<spam>\d+);', singleCmtDwrStr);
        spam = foundSpam.group("spam");
        curCmtDict['spam'] = spam;
        logging.debug("spam=%s", spam);
 
        #subComments
        #s0.subComments=s1;
        foundSubComments = re.search(strSn + '\.subComments=(?P<subComments>.+?);', singleCmtDwrStr);
        subComments = foundSubComments.group("subComments");
        curCmtDict['subComments'] = subComments;
        logging.debug("subComments=%s", subComments);
 
        #valid
        #s0.valid=0;
        foundValid = re.search(strSn + '\.valid=(?P<valid>\d+);', singleCmtDwrStr);
        valid = foundValid.group("valid");
        curCmtDict['valid'] = valid;
        logging.debug("valid=%s", valid);
    else:
        #process main comment remaing field
 
 
        #main comment dwr string:
        #s0.commentCount=0;s0.content="\u7EC8\u4E8E\u6709iphone\u7248\u7684\u4E86";s0.id="148749270";s0.mainCommentCount=0;s0.moodType=0;s0.moveFrom="iphone";s0.publishTime=1374626867596;s0.synchMiniBlog=-1;s0.userAvatar=0;s0.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.userId=186541395;s0.userName="ni_chen";s0.userNickname="Neysa";
 
        #s1.commentCount=1;s1.content="\u4E3B\u9875\u7EC8\u4E8E\u7545\u901A\u4E86\uFF0C\u4FFA\u53C8\u8981\u632A\u7A9D\u4E86[P]\u5FAE\u7B11[/P]";s1.id="134875456";s1.mainCommentCount=1;s1.moodType=1;s1.moveFrom=null;s1.publishTime=1350461318140;s1.synchMiniBlog=-1;s1.userAvatar=0;s1.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s1.userId=186541395;s1.userName="ni_chen";s1.userNickname="Neysa";
 
        #s2.commentCount=0;s2.content="BK\u529E\u516C\u5BA4\u5927\u5988\u771F\u662F\u540D\u4E0D\u865A\u4F20\uFF0C\u5976\u5976\u7684\u4ECA\u5929\u8FD8\u4E0D\u7ED3\u675F\u6211\u8981\u6297\u8BAE\u4E86";s2.id="134892431";s2.mainCommentCount=0;s2.moodType=1;s2.moveFrom=null;s2.publishTime=1350454487895;s2.synchMiniBlog=-1;s2.userAvatar=0;s2.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s2.userId=186541395;s2.userName="ni_chen";s2.userNickname="Neysa";
 
        #s3.commentCount=0;s3.content="\u7814\u7A76\u5BA4\u5C0F\u5B69\u8981\u53BB\u89C1IU\uFF0C\u8FD8\u9884\u7EA6\u4E86\u76AE\u80A4\u7BA1\u7406\uFF0C\u4E24\u4E2A\u4EBA\u5728\u90A3\u5600\u5495\u201C\u8FD9\u6837\u62FF\u4E0D\u5230IU\u7B7E\u540D\u7684.....\u201D[P]\u5931\u671B[/P][P]\u5931\u671B[/P]";s3.id="134892313";s3.mainCommentCount=0;s3.moodType=1;s3.moveFrom=null;s3.publishTime=1350443478140;s3.synchMiniBlog=-1;s3.userAvatar=0;s3.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s3.userId=186541395;s3.userName="ni_chen";s3.userNickname="Neysa";
 
 
        #commentCount
        #s0.commentCount=0;
        foundCommentCount = re.search(strSn + '\.commentCount=(?P<commentCount>\d+);', singleCmtDwrStr);
        commentCount = foundCommentCount.group("commentCount");
        curCmtDict['commentCount'] = commentCount;
        logging.debug("commentCount=%s", commentCount);
 
 
        #mainCommentCount
        #s0.mainCommentCount=0;
        foundMainCommentCount = re.search(strSn + '\.mainCommentCount=(?P<mainCommentCount>\d+);', singleCmtDwrStr);
        mainCommentCount = foundMainCommentCount.group("mainCommentCount");
        curCmtDict['mainCommentCount'] = mainCommentCount;
        logging.debug("mainCommentCount=%s", mainCommentCount);
 
        #moodType
        #s0.moodType=0;
        foundMoodType = re.search(strSn + '\.moodType=(?P<moodType>\d+);', singleCmtDwrStr);
        moodType = foundMoodType.group("moodType");
        curCmtDict['moodType'] = moodType;
        logging.debug("moodType=%s", moodType);
 
        #userAvatar
        #s0.userAvatar=0;
        foundUserAvatar = re.search(strSn + '\.userAvatar=(?P<userAvatar>\d+);', singleCmtDwrStr);
        userAvatar = foundUserAvatar.group("userAvatar");
        curCmtDict['userAvatar'] = userAvatar;
        logging.debug("userAvatar=%s", userAvatar);
 
        #userAvatarUrl
        #s0.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";
        foundUserAvatarUrl = re.search(strSn + '\.userAvatarUrl="?(?P<userAvatarUrl>http://.+?)"?;', singleCmtDwrStr);
        userAvatarUrl = foundUserAvatarUrl.group("userAvatarUrl");
        curCmtDict['userAvatarUrl'] = userAvatarUrl;
        logging.debug("userAvatarUrl=%s", userAvatarUrl);
 
        #userName
        #s0.userName="ni_chen";
        foundUserName = re.search(strSn + '\.userName="?(?P<userName>.+?)"?;', singleCmtDwrStr);
        userName = foundUserName.group("userName");
        curCmtDict['userName'] = userName;
        logging.debug("userName=%s", userName);
 
        #userNickname
        #s0.userNickname="Neysa";
        foundUserNickname = re.search(strSn + '\.userNickname="?(?P<userNickname>.+?)"?;', singleCmtDwrStr);
        userNickname = foundUserNickname.group("userNickname");
        curCmtDict['userNickname'] = userNickname;
        logging.debug("userNickname=%s", userNickname);
 
    return curCmtDict;
 
def parseSubCmtDwrStrToSubCmtDictList(subCmtDwrStr):
    """
        parse sub comment dwr string to sub comment dict list
            split to single sub comment dwr string list
            convert each sub comment dwr string to dict
    """
    subCmtDictList = [];
     
    # //#DWR-INSERT
    # //#DWR-REPLY
    # var s0={};var s1=[];s0.cardId="134875456";s0.content="\u81EA\u5DF1\u4E70\u70B9\u6C34\u679C\u5403\u3002";s0.id="73300019";s0.ip="203.234.215.66";s0.ipName=null;s0.lastUpdateTime=1351380367156;s0.mainComId="-1";s0.moveFrom=null;s0.popup=false;s0.publishTime=1351380367155;s0.publisherAvatar=0;s0.publisherAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.publisherId=55976067;s0.publisherName="chenlin198412@126";s0.publisherNickname="Lynn";s0.publisherUrl=null;s0.replyComId="-1";s0.replyToUserId=186541395;s0.replyToUserName="ni_chen";s0.replyToUserNick="Neysa";s0.spam=0;s0.subComments=s1;s0.synchMiniBlog=false;s0.userId=186541395;s0.valid=0;
    # dwr.engine._remoteHandleCallback('1','0',[s0]);
     
    subCmtStrList = re.findall(r's\d+\.cardId=.+?s\d+\.valid=\d+;(?:\s)', subCmtDwrStr);
    #logging.info("subCmtStrList=%s", subCmtStrList);
    logging.debug("len(subCmtStrList)=%d", len(subCmtStrList));
     
    if(subCmtStrList):
        for singleSubCmtDwrStr in subCmtStrList:
            singleSubCmtDict = parseSingleDwrStrToCmtDict(singleSubCmtDwrStr);
            subCmtDictList.append(singleSubCmtDict);
 
    return subCmtDictList;
 
def parseMainCmtDwrStrToMainCmtDictList(respDwrReplyStr):
    """
        Parse main comment response DWR-REPLY string, into comment dict list
    """
    commentDictList = [];
    #s0.commentCount=0;s0.content="\u7EC8\u4E8E\u6709iphone\u7248\u7684\u4E86";s0.id="148749270";s0.mainCommentCount=0;s0.moodType=0;s0.moveFrom="iphone";s0.publishTime=1374626867596;s0.synchMiniBlog=-1;s0.userAvatar=0;s0.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s0.userId=186541395;s0.userName="ni_chen";s0.userNickname="Neysa";
 
    #s1.commentCount=1;s1.content="\u4E3B\u9875\u7EC8\u4E8E\u7545\u901A\u4E86\uFF0C\u4FFA\u53C8\u8981\u632A\u7A9D\u4E86[P]\u5FAE\u7B11[/P]";s1.id="134875456";s1.mainCommentCount=1;s1.moodType=1;s1.moveFrom=null;s1.publishTime=1350461318140;s1.synchMiniBlog=-1;s1.userAvatar=0;s1.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s1.userId=186541395;s1.userName="ni_chen";s1.userNickname="Neysa";
 
    #s2.commentCount=0;s2.content="BK\u529E\u516C\u5BA4\u5927\u5988\u771F\u662F\u540D\u4E0D\u865A\u4F20\uFF0C\u5976\u5976\u7684\u4ECA\u5929\u8FD8\u4E0D\u7ED3\u675F\u6211\u8981\u6297\u8BAE\u4E86";s2.id="134892431";s2.mainCommentCount=0;s2.moodType=1;s2.moveFrom=null;s2.publishTime=1350454487895;s2.synchMiniBlog=-1;s2.userAvatar=0;s2.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s2.userId=186541395;s2.userName="ni_chen";s2.userNickname="Neysa";
 
    #s3.commentCount=0;s3.content="\u7814\u7A76\u5BA4\u5C0F\u5B69\u8981\u53BB\u89C1IU\uFF0C\u8FD8\u9884\u7EA6\u4E86\u76AE\u80A4\u7BA1\u7406\uFF0C\u4E24\u4E2A\u4EBA\u5728\u90A3\u5600\u5495\u201C\u8FD9\u6837\u62FF\u4E0D\u5230IU\u7B7E\u540D\u7684.....\u201D[P]\u5931\u671B[/P][P]\u5931\u671B[/P]";s3.id="134892313";s3.mainCommentCount=0;s3.moodType=1;s3.moveFrom=null;s3.publishTime=1350443478140;s3.synchMiniBlog=-1;s3.userAvatar=0;s3.userAvatarUrl="http://img.bimg.126.net/photo/hmZoNQaqzZALvVp0rE7faA==/0.jpg";s3.userId=186541395;s3.userName="ni_chen";s3.userNickname="Neysa";
     
    mainCmtDwrStrList = [];
 
    #mainCmtDwrStrList = re.findall(r'(?:s\d+)\.commentCount=.+?\1\.userNickname=".+?";', respDwrReplyStr);
    mainCmtDwrStrList = re.findall(r's\d+\.commentCount=.+?s\d+\.userNickname=".+?";(?:\s)', respDwrReplyStr);
    #logging.info("mainCmtDwrStrList=%s", mainCmtDwrStrList);
    logging.debug("len(mainCmtDwrStrList)=%d", len(mainCmtDwrStrList));
     
    if(mainCmtDwrStrList):
        for eachMainCmtDwrStr in mainCmtDwrStrList:
            #parse each main comment string into comment dict
            singleMainCmtDict = parseSingleDwrStrToCmtDict(eachMainCmtDwrStr);
 
            #add single comment dict into list
            commentDictList.append(singleMainCmtDict);
 
    return commentDictList;
 
#------------------------------------------------------------------------------
def fillComments_fellingCard(destCmtDict, srcCmtDict):
    """
        fill source comments dictionary into destination comments dictionary
            note:
            here srcCmtDict may be is main comment dict or sub comment dict
    """
    logging.debug("--------- source comment: idx=%d, num=%d ---------", srcCmtDict['curCmtIdx'], srcCmtDict['curCmtNum']);
    #for item in srcCmtDict.items() :
    #    logging.debug("%s", item);
    destCmtDict['id'] = srcCmtDict['curCmtNum'];
 
    if(srcCmtDict['isSubComment']):
        destCmtDict['author'] = srcCmtDict['publisherNickname'];
    else:
        destCmtDict['author'] = srcCmtDict['userNickname'];
    #logging.info("done for author");
 
    if(srcCmtDict['isSubComment']):
        destCmtDict['author_email'] = srcCmtDict['publisherName'];#s0.publisherName="chenlin198412@126";
    else:
        destCmtDict['author_email'] = "";
    #logging.info("done for author_email");
         
    if(srcCmtDict['isSubComment']):
        destCmtDict['author_url'] = saxutils.escape(genNeteaseUserUrl(srcCmtDict['publisherName']));
    else:
        destCmtDict['author_url'] = saxutils.escape(gVal['blogEntryUrl']);
    #logging.info("done for author_url");
         
    if(srcCmtDict['isSubComment']):
        destCmtDict['author_IP'] = srcCmtDict['ip'];
    else:
        destCmtDict['author_IP'] = "";
    #logging.info("done for author_IP");
 
    # method 1:
    #epoch1000 = srcCmtDict['publishTime']
    #epoch = float(epoch1000) / 1000
    #localTime = time.localtime(epoch)
    #gmtTime = time.gmtime(epoch)
    # method 2:
     
    #s0.publishTime=1374626867596;
    #s4.publishTime=1348561288458;
    publishTimeStr = srcCmtDict['publishTime'];
    #logging.info("publishTimeStr=%s", publishTimeStr);
    publishTimeStrInt = int(publishTimeStr);
    publishTimeStrIntSec = publishTimeStrInt/1000;
    publishTimeStrIntSecStr = str(publishTimeStrIntSec);
    localTime = crifanLib.timestampToDatetime(publishTimeStrIntSecStr);
    #logging.info("localTime=%s", localTime);
    #pubTimeStr = srcCmtDict['shortPublishDateStr'] + " " + srcCmtDict['publishTimeStr'];
    #localTime = datetime.strptime(pubTimeStr, "%Y-%m-%d %H:%M:%S");
    gmtTime = crifanLib.convertLocalToGmt(localTime);
    destCmtDict['date'] = localTime.strftime("%Y-%m-%d %H:%M:%S");
    destCmtDict['date_gmt'] = gmtTime.strftime("%Y-%m-%d %H:%M:%S");
    #logging.info("done for date and date_gmt");
 
    # handle some speical condition
    #logging.debug("before decode, coment content:\n%s", srcCmtDict['content']);
    #cmtContent = srcCmtDict['content'].decode('unicode-escape'); # convert from \uXXXX to character
    cmtContent = srcCmtDict['content'];
    #logging.debug("after decode, coment content:\n%s", cmtContent);
    destCmtDict['content'] = cmtContent;
    #logging.info("done for content");
     
    destCmtDict['approved'] = 1;
    destCmtDict['type'] = '';
    destCmtDict['parent'] = srcCmtDict['parentCmtNum'];
    destCmtDict['user_id'] = 0;
 
    logging.debug("author=%s", destCmtDict['author']);
    logging.debug("author_email=%s", destCmtDict['author_email']);
    logging.debug("author_IP=%s", destCmtDict['author_IP']);
    logging.debug("author_url=%s", destCmtDict['author_url']);
    logging.debug("date=%s", destCmtDict['date']);
    logging.debug("date_gmt=%s", destCmtDict['date_gmt']);
    logging.debug("content=%s", destCmtDict['content']);
    logging.debug("parent=%s", destCmtDict['parent']);
 
    return destCmtDict;
 
#------------------------------------------------------------------------------
# fetch and parse comments 
# return the parsed dict value
def fetchAndParseComments(url, html):
    cmtRespDictList = [];
    parsedCommentsList = [];
 
    if(url == gVal['special']['feelingCard']['url']):
        cmtRespDictList = fetchComments_feelingCard();
        if(cmtRespDictList) :
            # got valid comments, now proess it
            for cmtDict in cmtRespDictList :
                comment = {};
                #fill all comment field
                comment = fillComments_fellingCard(comment, cmtDict);
                parsedCommentsList.append(comment);
    else:
        #extract comments if exist
        soup = htmlToSoup(html);
        cmtRespDictList = fetchComments(url, soup);
        #logging.info("cmtRespDictList=%s", cmtRespDictList);
        if(cmtRespDictList) :
            # got valid comments, now proess it
            for cmtDict in cmtRespDictList :
                comment = {};
                #fill all comment field
                comment = fillComments(comment, cmtDict);
                parsedCommentsList.append(comment);
 
    return parsedCommentsList;