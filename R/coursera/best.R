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
        if (flag == 0) #state ������Ч
        {
                stop("invalid state")
        }
        #��������outcome�Ϸ���
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
        ##########�ؼ���䣬���factor�������⣡������������������
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
##########�Զ�������
#datagrp <- factor(grp, levels=c("1.1", "8.7", "10.1"), ordered=TRUE)
####���� b, c, a��˳��

#    ����factor����levels "1.1", "10.1", "8.7" �������20��Ԫ��
#    grp <- factor(sample(c("10.1", "8.7", "1.1"), 20, replace = TRUE))
#    datagrp <- factor(grp, levels=c("1.1", "8.7", "10.1"), ordered=TRUE)
#    ����������̬�������
#    val1 <- rnorm(20)
#    val2 <- rnorm(20)
#    ���ݿ����
#    dat <- data.frame(grp = grp, val1 = val1, val2 = val2)
#    data <-data.frame(datagrp = datagrp,val1 = val1, val2 = val2)
#    �Ե�һ��Ϊ��׼����
#    newdat <- dat[order(dat[, 1]), ]
#    newdata <- data[order(data[, 1]), ]
#    �Ե�һ�еĶ������ ��� 
#    tapply(newdat[, 2], newdat[, 1], sum)
######### stringsAsFactors=FALSE �ַ�����תΪ���Ӹ�ʽ