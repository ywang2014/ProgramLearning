corr <- function(directory, threshold = 0)
{
        result <- complete(directory, 1:332);
        suitable <- result["nobs"] > threshold;
        data_id <- result["id"][suitable];
        old.dir <- getwd();
        setwd(directory);
        b <- NULL;
        if (length(data_id) < 1)
        {
                b
        }
        else
        {
                for (i in 1:length(data_id))
                {
                        if (data_id[i] < 10)
                        {
                                name <- paste("00", data_id[i], sep = "");
                        }
                        else if (data_id[i] < 100)
                        {
                                name <- paste("0", data_id[i], sep = "");
                        }
                        else 
                        {
                                name <- data_id[i]
                        }
                        file <- paste(name, "csv", sep = "."); ###得到打开文件的文件名
                        s_data <- na.omit(read.csv(file));
                        a <- cor(s_data["nitrate"],s_data["sulfate"]);
                        b <- c(b, a);
                }
                round(b, 5)
        }
        setwd(old.dir);
        b
}