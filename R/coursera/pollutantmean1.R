pollutantmean <- function(directory, pollutant, id = 1:332)
{
        old.dir <- getwd(); ##保存当前工作目录
        setwd(directory);   ##设置新的工作目录
        output <- 0;
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
                        name <- id[i]
                }
                file <- paste(name, "csv", sep = "."); ###得到打开文件的文件名
                s_data <- read.csv(file);
                temp_data <- s_data[pollutant];
                bad <- is.na(temp_data);
                temp <- mean(temp_data[!bad]);
                output <- output + round(temp, 3);
        }
        setwd(old.dir); ##返回原始工作空间
        round(output/length(id), 3)     
}
#pollutantmean("D:/Development/BigData/coursera/specdata", "sulfate", 1:10)
#pollutantmean("D:/Development/BigData/coursera/specdata","nitrate",70:72)
#pollutantmean("specdata", "sulfate", 1:10) 4.064
######D:\Development\BigData\coursera\specdata
#####pollutantmean <- function("D:/Development/BigData/coursera/specdata", pollutant, id = 001)
#######paste("a","b"),字符拼接，但是中间有空格
#######data<-paste("网站停留时间:","3小时",data,sep="")