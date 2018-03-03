/**
	美团一面面试题
	技术聊了很多：
		1.微服务的优缺点   
		2.RPC调用协议（HTTP or TCP）
		3.redis，分布式锁实现
		4.MySQL索引结构
		5.数据库隔离级别：文件数据库是串行的
		6.缓存技术
		
		项目：
			数据库优化和缓存技术
		
*/

// 有序数组两个，合并有序数组
int *mergeTwoSortedArray(int *A, int a_n, int *B, int b_n){
    if (A == nullptr || a_n < 1 || B == nullptr || b_n < 1){
        return ;    // invalid parameter
    }
    int *result = new int[a_n + b_n];
    int ai = 0;    // A array index
    int bi = 0;    // B array index
    int ri = 0;    // result array index
    while (ai < a_n || bi < b_n){
        if ((bi >= b_n) || (ai < a_n && A[ai] < B[bi])){
            result[ri++] = A[ai++];
        }
        if ((ai >= a_n) || (bi < b_n && B[bi] < A[ai])){
            result[ri++] = B[bi++];
        }
    }
    return result;
}