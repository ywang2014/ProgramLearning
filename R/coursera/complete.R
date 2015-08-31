complete <- function(directory, id = 1:332)
{
        old.dir <- getwd();
        setwd(directory);
        nobs <- NULL;
        for (i in 1:length(id))
        {
                if (id[i] < 10)
                {
                        name <- paste("00", id[i], sep = "");
                }
                else if (id[i] < 100)
                {
                        name <- paste("0", id[i], sep = "");
                }
                else 
                {
                        name <- id[i];
                }
                file <- paste(name, "csv", sep = ".");
                s_data <- read.csv(file);
                nobs_data <- na.omit(s_data); ###忽略有缺失值得数据
                nobs_len <- length(nobs_data[,1]); ##区向量才能计算
                                               ###长度length(data[1])=1
                ######将nobs放入数组
                nobs <- c(nobs, nobs_len);
        }
        setwd(old.dir); ##返回原始工作空间
        data.frame(id,nobs)
      
      #  setwd("D:/Development/BigData/coursera");
      ###  expand.grid(id=id, nodes=nobs_array); ####生成输出    
}
#complete("D:/Development/BigData/coursera/specdata",id = 1:30)
########expand.grid(id ="1",nodes="2")  #生成输出
########data.frame(x,n) x <- 1:4, n <- 3