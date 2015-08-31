pollutantmean <- function(directory, pollutant, id = 1:332)
{
        total_sum <- 0;
        total_length <- 0;
        for (i in 1:length(id))
        {
                if (id[i] < 10)
                {
                        name <- paste0("00", id[i]);
                }
                else if (id[i] < 100)
                {
                        name <- paste0("0", id[i]);
                }
                else
                {
                        name <- id[i];
                }
                file <- paste0(directory, "/", name, ".csv");
                r_data <- read.csv(file);
                data <- r_data[, pollutant];
                bad <- is.na(data);
                total_sum <- total_sum + sum(data[!bad]);
                total_length <- total_length + length(data[!bad]);
        }
        ## 不能直接使用mean函数，没有去NA项的个数
        mean <- total_sum/total_length;
        mean
}