# R������
## Elapsed time > user time ����ʱ��>�û�ʱ��
## �ȴ����ݾ������紫�ݵ������
## �����û�ʱ��̣�����ʱ�䳤
system.time(readLines("http://www.jhsph.edu"))
##   �û�  ϵͳ  ���� 
##   0.81  0.16 13.60 

## Elapsed time < user time
## ��������һ��ϣ�������;���
## svd()������������ֵ�ֽ�(singular value decomposition)
## svdʹ��ƻ������Accelerate��ܣ����߳����Դ�����
## �������ü������˫�ˣ��û�ʱ��=2*����ʱ��
hilbert <- function(n)
{
        i <- 1:n
        1 / outer(i - 1, i, "+")
}
x <- hilbert(1000)
system.time(svd(x))
## �û�  ϵͳ  ���� 
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
##    �û� ϵͳ ���� 
##    0.57 0.02 0.67

###########################################
Rprof()  ## R ������
summaryRprof() ##ȡ�������������
#############����ͬʱʹ��
#Rprof�����ڹ��ɵ�����ȡ���ڼ�¼׷�ٺ�������ջ
# ʱ�����0.02s
by.total #��ÿ������ʹ�õ�ʱ������������ʱ������
by.self  #�ȼ�ȥ����ջ��֮ǰ�ĺ����ķѵ�ʱ�䣬��...