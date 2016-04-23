/**
	百度实习生笔试题1：
	
	对于短作业优先(SJF)系统，计算作业平均等待时间。等待时间 = 开始执行时间 - 请求时间 
	当作业处理时间相等时，请求时间早的作业优先执行。
	单处理器，一次只能执行一个作业。
	
	输入：1.任务请求时间序列，请求时间序列，按照请求时间的大小已排序。
		  2.任务对应的执行时间序列。
		  3.序列长度
*/

struct task{
    int rTime;
    int dTime;
    int sTime;
    int eTime;
};


float waitingTimeSJF(int *requestTimes, int *durations, int n)
{
    // WRITE YOUR CODE HERE
    if (requestTimes == NULL || durations == NULL || n < 1){
        return 0;   // invalid args
    }
    
    task *arr = new task[n];
    bool *done = new bool[n];
    for (int i = 0; i < n; i++)
    {
        done[i] = false;
    }
    
    int index = 1;
    int minDur = durations[0];
    int minIndex = 0;
    while (index < n && requestTimes[0] == requestTimes[index]){
        if (minDur > durations[index]){
            minDur = durations[index];
            minIndex = index;
        }   // 从前往后，自然相等的时候，取最小的requestTime
        index++;
    }
    int t_index = 0;
    arr[t_index].sTime = arr[t_index].rTime = requestTimes[minIndex];
    arr[t_index].dTime = durations[minIndex];
    arr[t_index].eTime = arr[t_index].sTime + arr[t_index].dTime;
    t_index++;
    done[minIndex] = true;
    
    int count = 1;
    float sum = (float)0.0;
    while (t_index < n){
        int endTime = arr[t_index - 1].eTime;
        for (int i = 0; i < n; i++)
        {
            if (!done[i]){
                index = i;
                break;
            }
        }
        if (index == n){
            break;
        }
        minDur = durations[index];
        minIndex = index++;
        while (index < n && requestTimes[index] <= endTime ){
            if (!done[index] && minDur > durations[index]){
                minDur = durations[index];
                minIndex = index;
            }
            index++;
        }
        arr[t_index].sTime = endTime;
        arr[t_index].rTime = requestTimes[minIndex];
        arr[t_index].dTime = durations[minIndex];
        arr[t_index].eTime = arr[t_index].sTime + arr[t_index].dTime;
        t_index++;
        done[minIndex] = true;
        sum += arr[t_index].sTime - arr[t_index].rTime;
    }
    
    return (float)(sum / n);
}


/********************************************************************/
// 新版本
float waitingTimeSJF(int *requestTimes, int *durations, int n)
{
    // WRITE YOUR CODE HERE
    if (requestTimes == NULL || durations == NULL || n < 1){
        return 0;   // invalid args
    }
    
    task *arr = new task[n];
    bool *done = new bool[n];
    for (int i = 0; i < n; i++)
    {
        done[i] = false;
    }
    
    int index = 1;
    int minDur = durations[0];
    int minIndex = 0;
    while (index < n && requestTimes[0] == requestTimes[index]){
        if (minDur > durations[index]){
            minDur = durations[index];
            minIndex = index;
        }   // 从前往后，自然相等的时候，取最小的requestTime
        index++;
    }
    int endTime = requestTimes[minIndex] + durations[minIndex];
    done[minIndex] = true;
    
    int count = 1;
    float sum = (float)0.0;
	int t_index = 1;
    while (t_index < n){
        for (int i = 0; i < n; i++)
        {
            if (!done[i]){
                index = i;
                break;
            }
        }
        if (index == n){
            break;
        }
        minDur = durations[index];
        minIndex = index++;
        while (index < n && requestTimes[index] <= endTime ){
            if (!done[index] && minDur > durations[index]){
                minDur = durations[index];
                minIndex = index;
            }
            index++;
        }
		
        sum += endTime - requestTimes[minIndex];
		endTime += durations[minIndex];
		done[minIndex] = true;
        t_index++;
    }
    
    return (float)(sum / n);
}


/********************************************************************/
// 新版本2
float waitingTimeSJF(int *requestTimes, int *durations, int n)
{
    // WRITE YOUR CODE HERE
    if (requestTimes == NULL || durations == NULL || n < 1){
        return 0;   // invalid args
    }
    
    task *arr = new task[n];
    bool *done = new bool[n];
    for (int i = 0; i < n; i++)
    {
        done[i] = false;
    }
    
    int index = 1;
    int minDur = durations[0];
    int minIndex = 0;
    while (index < n && requestTimes[0] == requestTimes[index]){
        if (minDur > durations[index]){
            minDur = durations[index];
            minIndex = index;
        }   // 从前往后，自然相等的时候，取最小的requestTime
        index++;
    }
    int endTime = requestTimes[minIndex] + durations[minIndex];
    done[minIndex] = true;
    
    int count = 1;
    float sum = (float)0.0;
	int t_index = 1;
	int start = 0;	// 记录搜索任务的起点
    while (t_index < n){
		// 寻找出第一个未处理的任务
        for (int i = start; i < n; i++)
        {
            if (!done[i]){
                index = i;
                break;
            }
        }
        if (index == n){
            break;
        }
			
		start = index + 1;	// 下次搜索的起点，优化效率，不需要每次从0开始
		
        minDur = durations[index];
        minIndex = index++;
        while (index < n && requestTimes[index] <= endTime ){
            if (!done[index] && minDur > durations[index]){
                minDur = durations[index];
                minIndex = index;
            }
            index++;
        }
		
        sum += endTime - requestTimes[minIndex];
		endTime += durations[minIndex];
		done[minIndex] = true;
        t_index++;
    }
    
    return (float)(sum / n);
}