###################################################
用R命令直接设置java_home
Sys.setenv(JAVA_HOME='C:/Program Files (x86)/Java/jre1.8.0_40')
Sys.setenv(JAVA_HOME='D:/Java/jdk1.8.0_25/jre')
#### 32位java与64位R矛盾 在 Tools---global options---general(可以解决)
####  但是不能读数据read.xlsx
##### 安装64位仍然问题
#由于想使用rmmseg4j来用中文分词，因而必须安装rJava。但发现出现问题：
#
#Error : .onLoad failed in loadNamespace() for 'rJava', details:
#        call: inDL(x, as.logical(local), as.logical(now), ...)
#error: 无法载入共享目标对象‘D:/program/R/R-2.15.1/library/rJava/libs/x64/rJava.dll’：:
#        LoadLibrary failure:  %1 不是有效的 Win32 应用程序。
#
#此外: 警告信息：
#程辑包‘rJava’是用R版本2.15.3 来建造的 
#错误: ‘rJava’程辑包/名字空间载入失败，

#问题描述： R查找dll文件有问题

#解决方法： 添加C:\Program Files\Java\jdk1.6.0_10\jre\bin\server环境变量path，即将jvm.dll这个库加入。 然后重启RStudio
#### 解决了
##### Quiz1
fileUrl <- "https://d396qusza40orc.cloudfront.net/getdata%2Fdata%2Fss06hid.csv "
download.file(fileUrl, destfile = "community.csv")
# data <- read.table("community.csv")
data <- read.csv("community.csv")
newdata <- data$VAL
a <- s == 24
b <- s[a]
bad <- is.na(b)
c <- b[!bad]
length(c)

fileUrl2 <- "https://d396qusza40orc.cloudfront.net/getdata%2Fdata%2FDATA.gov_NGAP.xlsx "
download.file(fileUrl2, destfile = "Gas.xlsx")
dateDownloaded <- date()
library(rJava)
library(xlsxjars)
library(xlsx)
#### 必须载入 rJava xlsxjars
#gasdata <- read.xlsx("Gas-Aquisition-Program.xlsx", sheetIndex=1, header=TRUE)
### 文件无效，才打不开

gasdata <- read.xlsx("DATA.gov_NGAP.xlsx", sheetIndex=1, header=TRUE)