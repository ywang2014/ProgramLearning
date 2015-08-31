################assignment4
set.seed(1)
rpois(5, 2)
###具有数字 1, 1, 2, 4, 1 的向量
dnorm() 概率密度(probability density)函数
pnorm() 累计分布(cumulative distribution)函数
rnorm() 随机正态分布
qnorm() 分位函数
d 估计已知均值和标准差的概率分布密度
r 产生随机数
p 估计累积分布
q 估计分位数

set.seed()函数：指明R应该使用哪个随机数字生成算法，以保证连贯性和可复制性

set.seed(10)
x <- rbinom(10, 10, 0.5) #二项分布随机数
e <- rnorm(10, 0, 20)
y <- 0.5 + 2 * x + e
plot(x, y)




