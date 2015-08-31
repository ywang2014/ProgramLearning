# data cleaning 
if (!file.exist("data")) #检查文件目录是否存在
{
        dir.create("data")  #创建文件夹
}
fileUrl <- "https://data.baltimorecity.gov/api/views/dz54-2aru/rows.csv?accessType=DOWNLOAD"
download.file(fileUrl, destfile = "cameras.csv", method = "curl")
# 下载数据 Mac-OS 使用“curl” Windows 使用默认即可
dateDownLoaded <- date() # 下载日期
cameraData <- read.table("./data/cameras.csv")
# read.table 直接读入内存，不适合大数据。鲁棒性好、灵活、慢
# 默认是制表符做分隔的
cameraData <- read.table("./data/cameras.csv", sep = ",", header = TRUE)
head(cameraData)

# quote="" ###解决'or" 的问题

####### 仅读取一个子集
colIndex <- 2:3
rowIndex <- 1:4
cameraDataSubset <- read.xlsx("./data/cameras.xlsx", sheetIndex=1, 
                              colIndex=colIndex, rowIndex=rowIndex)
XPath http://www.stat.berkeley.edu/~statcur/Workshop2/Presentations/XML.pdf

xpathSApply(rootNode, "//name", xmlValue)
### 遍历整个文档，找到所有标记为name的元素所在的节点，返回节点xml值(xmlValue)
xpathSApply(rootNode, "//price", xmlValue)

## 美国体育频道：橄榄球队 主页源代码
http://espn.go.com/nfl/team/_/name/bal/baltimore-ravens
fileUrl <- "http://espn.go.com/nf/team/_/name/bal/baltimore-ravens"
doc <- htmlTreeParse(fileUrl, useInternal = TRUE)
### 分析HTML文件htmlTreeParse；分析XML文件xmlTreeParse
scores <- xpathSApply(doc, "//li[@class='score']", xmlValue)
teams <- xpathSApply(doc, "//li[@class='team-name']", xmlValue)
scores


############### 安装swirl
## https://github.com/ywang2014/swirl_courses 下载到电脑
library(swirl)
install_course_zip("D:/Development/BigData/coursera/swirl_courses-master.zip", multi=TRUE, which_course="Getting_and_Cleaning_Data")
