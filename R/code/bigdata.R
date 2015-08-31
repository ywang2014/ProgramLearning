data <- read.csv("movie/users.dat",header = FALSE, sep = ":")
newdata <- data.frame(data[,1], data[,3], data[,5], data[,7])
newdata[, 2] <- as.numeric(newdata[, 2])
newdata2 <- matrix(data[1,],data[,5],data[,7]) #
#######   matrix(c, row, col)
a <- as.numeric(data[,1])
b <- as.numeric(data[,5])
c <- as.numeric(data[,7])
newdata3 <- martix(a,b,c)
a <- newdata[, 2] == "F"
newdata[, 2][a] <- 0
b <- newdata[, 2] == "M"
newdata[, 2][b] <- 1

write.table(newdata, file = "newusers.txt", sep="\t", col.name = NA)
write.table(newdata, file = "newusers2.txt",sep=" ", row.names=FALSE, col.names = FALSE)
#### 符合要求
sed -r 's/\|([0-9]+)/\n\1/g' a.txt >result.txt
# 以行为单位处理文本

data <- read.csv("movie/ratings.dat",header = FALSE, sep = ":")
newdata <- data.frame(data[,1], data[,3], data[,5])
write.table(newdata, file = "movie/newrating.txt",sep=" ", row.names=FALSE, col.names = FALSE)

data <- read.csv("movie/movies.dat",header = FALSE, sep = ":")
newdata <- data.frame(data[,1], data[,3], data[,5])
write.table(newdata, file = "movie/newmovie.txt", sep="|", row.names=FALSE, col.names = FALSE)
write.table(newdata, file = "movie/newmovie1.txt",quote = FALSE, sep="|", row.names=FALSE, col.names = FALSE)
data <- read.csv("movie/newmovie.txt",header = FALSE, sep = "|")
write.table(data, file = "movie/newmovie2.txt",quote = FALSE, sep="\t", row.names=FALSE, col.names = FALSE)
