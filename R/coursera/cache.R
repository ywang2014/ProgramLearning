#缓存向量平均值
makeVector <- function(x = numeric())
{
        m <- NULL
        set <- function(y) #设置向量值
        {
                x <<- y;
                m <<- NULL;
        }
        
        get <- function() #获取向量值
        {
                x;
        }
        
        setmean <- function(mean) #设置均值
        {
                m <<- mean;
        }
        
        getmean <- function() #获取平均值
        {
                m;
                #m <- mean(x);
                #mean <- mean(x);
        }
        # 返回的列表
        list(set = set, get = get,
             setmean = setmean,
             getmean = getmean)
}
###以下函数计算出了上述函数创建的特殊“向量”的平均值。
###首先查看是否已经计算了平均值。如果是这种情况，
#  那么它会从缓存中获取平均值并跳过计算。
#  否则，它会计算数据的平均值并通过setmean函数在缓存中设置平均值。

cachemean <- function(x, ...)
{
        m <- x$getmean()
        #print(m);
        if (!is.null(m))
        {
                message("getting cached data")
                return(m)
        }
        data <- x$get()
        #print(data);
        m <- mean(data, ...)
        #print(m);
        x$setmean(m)
        m
}

### source("cache.R")
### a = seq(1:30)
### b = makeVector(a)
### cachemean(b)