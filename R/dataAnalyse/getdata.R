# 在R中获取数据进行分析
# R可读取数据很多：
#       电子表格
#       Excel
#       数据库
#       图片
#       文本文件
#       其他格式

getwd() # 获取当前工作目录
setwd() # 设置数据文件保存目录

fdata <- scan("testsample.tex", what = "") # 从文本中获取数据
head(fdata)
fdata <- tolower(fdata)
ft <- table(fdata)      # 计算词的使用频率
pie(ft)         # 查看ft的饼图情况
max(ft)
head(ft)
dotchart(ft)    # 点图显示词使用频率
read.csv("test.csv", header = TRUE)
read.table("test.csv", header = TRUE)
# 直接从网上读取数据
data <- read.table("http://lib.statNaNu.edu/datasets/csb/ch3a.dat")

# 阅读电子表格数据，我们需要安装gdata库
install.packages("gdata")
library(gdata)
read.xls("test.xls")
x <- edit(as.data.frame(NULL))  # 通过编辑R填补传播表类型数据
data(Airpassengers)     # 将可用数据集置入R中
help(Airpassengers)     # 查看数据描述
head(Airpassengers)     # 查看实际数据
