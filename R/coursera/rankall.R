rankall <- function(outcome, num = "best")
{
        file <- "assign/rprog_data_ProgAssignment3-data/outcome-of-care-measures.csv"
        data <- read.csv(file);
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
        df <- data.frame(hospital=data[, 2], State=data[, 7], outcome=data[, column]);
        bad <- df[, 3] == "Not Available";
        df <- subset(df, !bad);
        df[, 3] <- suppressWarnings(as.numeric(levels(df[,3])[df[,3]]));
        #newdata <- split(df, State);
        #获得州向量，用于循环。
        state <- as.vector(df[, 2])
        state <- unique(state)
        state <- state[order(state)]
        #申明一个空的data.frame.
        newdf <- data.frame(hospital=c(NA), state=state, stringsAsFactors=FALSE);
        for (i in 1:length(state))
        {
                a <- df[, 2] == state[i] #必须是变量，终于发现错误了！！！！！
                new_df <- subset(df, a)
                d <- new_df[order(new_df[, 3], new_df[, 1]), ];
                if (num == "best")
                {
                        name <- as.character(d[1, 1]);
                }
                else if (num == "worst")
                {
                        name <- as.character(d[nrow(d), 1]);
                }
                else
                {
                        if (num > nrow(d))
                        {
                                name <- "<NA>";
                        }
                        else
                        {
                                name <- as.character(d[num, 1]);
                        }
                }
                #print(name);
                newdf[i, 1] <- name;
        }
        newdf
}
#######关键问题：factor排序错误