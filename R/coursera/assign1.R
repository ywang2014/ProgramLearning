assign <- function(){
x <- c(4, "a", TRUE)
x

x <- c(1, 3, 5)
y <- c(3, 2, 10)
rbind(x,y)

x <- list(2, "a", "b", TRUE)
x[[2]]

x <- 1:4
y <- 2
x+y

x <- c(17, 14, 4, 5, 13, 12, 10)
x[x > 10] <- 4
x
}
####################################################
 data <- read.csv("hw1_data.csv") #读取文件
 data #输出文件
 data[1] #输出第一列
 data[1,] #输出第一行
 data[i:j,] #输出i到j行
 nrow(data) #文件行数
 ncol() #文件列数
 data[,2]   #输出列，不带header
 bad <- is.na(data[,1]) #判断是否是不确定值
 data[,1][!bad] #去除不确定值之后的第一列数据
 mean(x) #均值
y <-  data["Ozone"]>31 #臭氧大于31
z <- data["Temp"]>90 #温度大于90
data[2][y][z] #第二列，且满足Y、Z条件
c <- data["Month"]==6 #Month=6
data["Temp"] #打印Temp列
mean(data["Temp"][c]) #计算均值：当“Month”为6时，“Temp”的平均值是多少？
####使用`names()' 函数来获得列的名字
####`tail()' 函数是提取R对象的最后几行的简便方法
####单边框 [ 操作可以提取数据帧的个别行



