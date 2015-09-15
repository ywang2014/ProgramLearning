pollutantmean <- function(directory, pollutant, id = 1:332)
{
        old.dir <- getwd(); ##���浱ǰ����Ŀ¼
        setwd(directory);   ##�����µĹ���Ŀ¼
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
                file <- paste(name, "csv", sep = "."); ###�õ����ļ����ļ���
                s_data <- read.csv(file);
                temp_data <- s_data[pollutant];
                bad <- is.na(temp_data);
                temp <- mean(temp_data[!bad]);
                output <- output + round(temp, 3);
        }
        setwd(old.dir); ##����ԭʼ�����ռ�
        round(output/length(id), 3)     
}
#pollutantmean("D:/Development/BigData/coursera/specdata", "sulfate", 1:10)
#pollutantmean("D:/Development/BigData/coursera/specdata","nitrate",70:72)
#pollutantmean("specdata", "sulfate", 1:10) 4.064
######D:\Development\BigData\coursera\specdata
#####pollutantmean <- function("D:/Development/BigData/coursera/specdata", pollutant, id = 001)
#######paste("a","b"),�ַ�ƴ�ӣ������м��пո�
#######data<-paste("��վͣ��ʱ��:","3Сʱ",data,sep="")