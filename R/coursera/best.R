best <- function(state, outcome)
{
        file <- "assign/rprog_data_ProgAssignment3-data/outcome-of-care-measures.csv"
        outcome_data <- read.csv(file);
        state_data <- as.vector(unique(outcome_data[, 7]));
        flag <- 0;
        for (i in 1:length(state_data))
        {
                if (state_data[i] == state)
                {
                        flag <- 1;
                }
        }
        if (flag == 0) #state 输入无效
        {
                stop("invalid state")
        }
        #检验输入outcome合法性
        s_outcome <- c("heart attack", "heart failure", "pneumonia")
        if (outcome == s_outcome[1])
        {
                column <- 11;
        }
        else if (outcome == s_outcome[2])
        {
                column <- 17;
        }
        else if (outcome == s_outcome[3])
        {
                column <- 23;
        }
        else
        {
                stop("invalid outcome")
        }
        data <- data.frame(outcome_data[, 2], outcome_data[, 7], outcome_data[, column], stringsAsFactors=FALSE);
        bad <- data[, 3] == "Not Available";
        data <- subset(data, !bad);
        #data <- data.frame(data[, 1], data[, 2], as.numeric(data[, 3]), stringsAsFactors=FALSE);
        #data <- data.frame(data[, 1], data[, 2], as.character(data[, 3]), stringsAsFactors=FALSE);
        good <- data[, 2] == state;
        data <- subset(data, good);
        ##########关键语句，解决factor排序问题！！！！！！！！！！
        data[, 3] <- suppressWarnings(as.numeric(levels(data[,3])[data[,3]]));
        #orderdata <- data[order(data[,column]),]
        #orderdata <- orderdata[complete.cases(orderdata),] 
        c <- data[order(data[,3], data[, 1]), ];
     #   c <- c[complete.cases(c), ];??????????
        d <- as.character(c[1, 1]);
        d
}
# best("NY", "pneumonia")
# best("NN", "pneumonia")
##########自定义排序
#datagrp <- factor(grp, levels=c("1.1", "8.7", "10.1"), ordered=TRUE)
####按照 b, c, a的顺序。

#    设置factor对象，levels "1.1", "10.1", "8.7" 随机生成20个元素
#    grp <- factor(sample(c("10.1", "8.7", "1.1"), 20, replace = TRUE))
#    datagrp <- factor(grp, levels=c("1.1", "8.7", "10.1"), ordered=TRUE)
#    生成两个正态随机变量
#    val1 <- rnorm(20)
#    val2 <- rnorm(20)
#    数据框对象
#    dat <- data.frame(grp = grp, val1 = val1, val2 = val2)
#    data <-data.frame(datagrp = datagrp,val1 = val1, val2 = val2)
#    以第一列为标准排序
#    newdat <- dat[order(dat[, 1]), ]
#    newdata <- data[order(data[, 1]), ]
#    以第一列的对象分类 求和 
#    tapply(newdat[, 2], newdat[, 1], sum)
######### stringsAsFactors=FALSE 字符不被转为因子格式