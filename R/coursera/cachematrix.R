#### 缓存逆矩阵


## 此函数用于创建可缓存逆矩阵的特殊“矩阵对象”
## 这个函数内部一共有两个变量：x和m
## x是需要处理的matrix
## m用来存储处理之后的结果

makeCacheMatrix <- function(x = matrix()) 
{
        #函数内部定义的变量，存放矩阵的逆矩阵
        inv <- NULL
        set <- function(y) #设置矩阵
        {
                x <<- y;
                inv <<- NULL;
        }
        
        get <- function() #获取矩阵
        {
                x;
        }
        
        setinverse <- function(inverse) #设置逆矩阵
        {
                inv <<- inverse;
        }
        
        getinverse <- function() #获取逆矩阵
        {
                inv;
        }
        # 返回的列表
        list(set = set, get = get,
             setinverse = setinverse,
             getinverse = getinverse)
}


## Write a short comment describing this function
## 函数用于计算上述makeCacheMatrix返回的特殊“矩阵”的逆矩阵。
## 如果已经计算逆矩阵（且尚未更改矩阵），那么cachesolve将检索缓存中的逆矩阵。
## 函数输入的x必须是正方形的可逆矩阵

cacheSolve <- function(x, ...) 
{
        ## x$getinverse()调用 makeCacheMatrix 中的 getinverse 函数
        ## 先查询一下之前有没有计算过逆矩阵
        inv <- x$getinverse()
        if (!is.null(inv))
        {
                ## inv不是 NULL，说明之前已经计算过逆矩阵
                message("getting cached data")
                ## 直接返回结果。
                return(inv)
        }
        # 函数如果执行到这一步，说明之前没有计算过逆矩阵。
        # 调用 x 内部的 get 函数，从 x 中调出需要处理的矩阵。
        matrix <- x$get()
        # 计算逆矩阵。
        inv <- solve(matrix, ...)
        # 调用 x 内部的 setinverse 函数，将得到的结果还存到 x 里面去；
        # 下次调用 cacheSolve 的时候，x 已经缓存了结果，
        # cacheSolve 函数会在之前的 if 查询中直接返回，不需要再计算了。
        x$setinverse(inv)
        # 返回结果。
        inv   ## Return a matrix that is the inverse of 'x'
}
