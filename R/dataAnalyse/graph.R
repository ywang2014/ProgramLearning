# R 数据可视化
        # 直方图
# install.packages("RColorBrewer") #安装RColorBrewer
library(RColorBrewer)
data(VADeaths)
par(mfrow = c(2, 3)) #清晰地把多个图放在一页上
# pal(n, name): n 颜色种类数，name 颜色样式
hist(VADeaths, breaks = 10, col = brewer.pal(3, "Set3"), main = "Set3 3 colors")
hist(VADeaths, breaks = 3, col = brewer.pal(3, "Set2"), main = "Set2 3 colors")
hist(VADeaths, breaks = 7, col = brewer.pal(3, "Set1"), main = "Set1 3 colors")
hist(VADeaths, breaks = 2, col = brewer.pal(8, "Set3"), main = "Set3 8 colors")
hist(VADeaths, col = brewer.pal(8, "Greys"), main = "Greys 8 colors")
hist(VADeaths, col = brewer.pal(8, "Greens"), main = "Greens 8 colors")

        #条形图/线形图
plot(AirPassengers, type = "1")

barplot(iris$Petal.Length)
barplot(iris$Sepal.Length, col = brewer.pal(3, "Set1"))
barplot(table(iris$Species, iris$Sepal.Length), col = brewer.pal(3, "Set1"))

        #箱式图
boxplot(iris$Petal.Length ~ iris$Species)

# 在屏幕上显示4个图
# 使用~ 将(萼片的长度)的伸展是如何跨各种类别(的物种)进行可视化
# 使用调色板创建醒目的图标
data(iris)
par(mfrow = c(2, 2))
boxplot(iris$Sepal.Length, col = "red")
boxplot(iris$Sepal.Length~iris$Species, col = "red")
boxplot(iris$Sepal.Length~iris$Species, col = heat.colors(3)) #调色板
boxplot(iris$Sepal.Length~iris$Species, col = topo.colors(3)) #调色板
# http://decisionstats.com/2011/04/21/using-color-palettes-in-r/

        # 散点图
plot(x = iris$Petal.Length)
plot(x = iris$Petal.Length, y = iris$Species)
plot(iris, col = brewer.pal(3, "Set1"))
    
        # 饼图
pie(table(iris$Species))
