/**
	百度实习生笔试题3：
	
	操作系统的虚拟内存的置换策略算法--先进先出算法的实现
	如果cache未满，发生缺页，则直接添加该页到cache，如果cache满了，发生缺页，则替换出待在cache中时间最长的页。
	计算一个给定的请求数组，发生缺页次数。
	
	例如：
	输入：2，{ 1 2 1 3 1 2 }，5		(cache大小，请求数组，数组长度)
	输出：5
*/

int countCacheMiss(int max_cache_size, int *page_requests, int len)
{
    // WRITE YOUR CODE HERE
    int *cache = new int[max_cache_size];
	for (int i = 0; i < max_cache_size; i++){
		cache[i] = -1;
	}
    cache[0] = page_requests[0];
	int count = 1;
    int index = 1;
	int num = 1;
	
    for (int i = 1; i < len; i++){
		bool find = false;
		for (int j = 0; j < num; j++){
			if (cache[j] == page_requests[i]){
				find = true;
			}
		}
		if (!find){
			index = index % max_cache_size;
			cache[index++] = page_requests[i];
			count++;
			if (num < max_cache_size){
				num++;
			}
		}
    }
    
    return count;
}