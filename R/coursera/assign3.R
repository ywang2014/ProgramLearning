#######看一下R自带的“iris”数据集
library(datasets)
data(iris)
#######获取数据集的描述
?iris
x <- iris["Species"] == "virginica" ###找出等于virginica的items
y <- iris[1][x]
mean(y) #####求均值  
#############你可以使用 'tapply' 来计算每个种类的 ‘Sepal.Length’ 平均值。
apply(iris[, 1:4], 2, mean) 
####返回含有变量“Sepal.Length”、“Sepal.Width”、“Petal.Length”和
####“Petal.Width”的平均值的向量
rowMeans(iris[, 1:4]) ###每一行的均值
colMeans(iris) ###列均值
#####加载R中的“mtcars”数据集 
library(datasets)
data(mtcars)
######通过汽车中的汽缸数(cyl)计算每加仑行驶的英里数(mpg)
sapply(split(mtcars$mpg, mtcars$cyl), mean)
apply(mtcars, 2, mean) ####计算每列平均数
sapply(mtcars, cyl, mean)###Error in match.fun(FUN) : object 'cyl' not found
mean(mtcars$mpg, mtcars$cyl)
####Error in mean.default(mtcars$mpg, mtcars$cyl) : 
####'trim'必需是长度必需为一的数值
y <- mtcars["cyl"] == 8
z <- mtcars["cyl"] == 4
a <- mean(mtcars[,4][y])
b <- mean(mtcars[,4][z])
a-b
debug(ls)