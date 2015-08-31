# R编译器
## Elapsed time > user time 运行时间>用户时间
## 等待数据经过网络传递到计算机
## 所以用户时间短，运行时间长
system.time(readLines("http://www.jhsph.edu"))
##   用户  系统  流逝 
##   0.81  0.16 13.60 

## Elapsed time < user time
## 函数建立一个希尔伯特型矩阵
## svd()计算矩阵的奇异值分解(singular value decomposition)
## svd使用苹果机的Accelerate框架，多线程线性代数库
## 可以利用计算机的双核：用户时间=2*运行时间
hilbert <- function(n)
{
        i <- 1:n
        1 / outer(i - 1, i, "+")
}
x <- hilbert(1000)
system.time(svd(x))
## 用户  系统  流逝 
## 14.39  0.03 15.60 

## Elapsed time = user time
system.time(
        {
                n <- 1000
                r <- numeric(n)
                for (i in 1:n)
                {
                        x <- rnorm(n)
                        r[i] <- mean(x)
                }
        })
##    用户 系统 流逝 
##    0.57 0.02 0.67

###########################################
Rprof()  ## R 分析器
summaryRprof() ##取分析器结果函数
#############不能同时使用
#Rprof可以在规律的样本取件内记录追踪函数调用栈
# 时间大于0.02s
by.total #把每个函数使用的时间依照总运行时间排序
by.self  #先减去调用栈中之前的函数耗费的时间，再...
