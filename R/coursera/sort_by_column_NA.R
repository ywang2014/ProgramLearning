sort_by_column_NA <- function(data,column)
{
        for (i in 3:4)
        {
                data[,i] <- suppressWarnings(as.numeric(levels(data[,i])[data[,i]]))
        }
        orderdata <- data[order(data[,column]),]
        orderdata <- orderdata[complete.cases(orderdata),] 
        return(orderdata)
}