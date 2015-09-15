#### ���������


## �˺������ڴ����ɻ������������⡰�������
## ��������ڲ�һ��������������x��m
## x����Ҫ������matrix
## m�����洢����֮��Ľ��

makeCacheMatrix <- function(x = matrix()) 
{
        #�����ڲ�����ı�������ž���������
        inv <- NULL
        set <- function(y) #���þ���
        {
                x <<- y;
                inv <<- NULL;
        }
        
        get <- function() #��ȡ����
        {
                x;
        }
        
        setinverse <- function(inverse) #���������
        {
                inv <<- inverse;
        }
        
        getinverse <- function() #��ȡ�����
        {
                inv;
        }
        # ���ص��б�
        list(set = set, get = get,
             setinverse = setinverse,
             getinverse = getinverse)
}


## Write a short comment describing this function
## �������ڼ�������makeCacheMatrix���ص����⡰���󡱵������
## ����Ѿ��������������δ���ľ��󣩣���ôcachesolve�����������е������
## ���������x�����������εĿ������

cacheSolve <- function(x, ...) 
{
        ## x$getinverse()���� makeCacheMatrix �е� getinverse ����
        ## �Ȳ�ѯһ��֮ǰ��û�м���������
        inv <- x$getinverse()
        if (!is.null(inv))
        {
                ## inv���� NULL��˵��֮ǰ�Ѿ�����������
                message("getting cached data")
                ## ֱ�ӷ��ؽ����
                return(inv)
        }
        # �������ִ�е���һ����˵��֮ǰû�м���������
        # ���� x �ڲ��� get �������� x �е�����Ҫ�����ľ���
        matrix <- x$get()
        # ���������
        inv <- solve(matrix, ...)
        # ���� x �ڲ��� setinverse ���������õ��Ľ�����浽 x ����ȥ��
        # �´ε��� cacheSolve ��ʱ��x �Ѿ������˽����
        # cacheSolve ��������֮ǰ�� if ��ѯ��ֱ�ӷ��أ�����Ҫ�ټ����ˡ�
        x$setinverse(inv)
        # ���ؽ����
        inv   ## Return a matrix that is the inverse of 'x'
}