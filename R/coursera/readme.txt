R语言编程

#                 #注释
dir()             #列出工作目录下的所有程序文件
ls()              #列出文件中所有的函数
source("name.R")  #加载程序
print(x)          #打印
a                 #对象，默认向量
a <- 1            #赋值语句，
a <- 1:20         #赋值，一个向量：1,2,3,4,5,···，20
a <- c("a","b","c') #character vector
a <- vector("numeric", length = 10) # a = 0 0 ···0：默认缺省值初始化
as.logical(x)     #强制类型转换（逻辑值T F）：as.
a <- matrix(nrow = 2, ncol = 3) #创建矩阵
dim(a)         #矩阵维度
attributes(a)  #矩阵属性
a <- matrix(1:6，nrow = 2, ncol = 3) #矩阵按列输入

m <- 1:10
dim(m) <- c(2:5) #创建矩阵方法二

x <- 1:3
y <- 10:12
cbind(x,y) #列向量构成矩阵
rbind(x,y) #行向量构成矩阵

x <- list(1, "a", TRUE, 1+4i) #list可以有不同对象
#####vector对象必须相同，character number logical(默认转化最低的（左边），不能逆向转化)