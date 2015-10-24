/**
* 经典排序算法：
*   归并排序：  稳定、O(NlogN)
*   快速排序：  不稳定、平均O(NlogN)，最坏O(N^2)
*   堆排序：    稳定、O(NlogN)
*   希尔排序：  稳定、O(NlogN)
*   桶排序：    ***、O(N)
*   冒泡排序：  稳定、O(N^2)
*   插入排序：  稳定、O(N^2)
*   选择排序：  稳定、O(N^2)
*   基数排序：  稳定、O(NlogN)
*/

#ifndef MYDORT_H
#define MYSORT_H
/********************* merge sort ***************************/
// typedef <template T>
void myMerge(int *arr, int lo, int mid, int hi)
{
    int i = 0, j= 0, k = 0;
    int l_len = mid - lo;   // 左边部分数组长度
    int r_len = hi - mid;   // 右边部分数组长度
    int l_arr[l_len];
    int r_arr[r_len];

    // 复制左右数组内容到临时数组
    /*
    * 换一种思路，直接此时排序到临时数组，排完序再复制回去即可！
    */
    for (i = 0; i < l_len; i++)
    {
        l_arr[i] = arr[lo+i];
    }
    for (i = 0; i < r_len; i++)
    {
        r_arr[i] = arr[mid+i];
    }

    i = lo;
    while (i < hi)
    {
        if (j < l_len && (k == r_len || l_arr[j] <= r_arr[k]))
        {
            arr[i++] = l_arr[j++];
        }
        if (k < r_len && (j == l_len || r_arr[k] < l_arr[j]))
        {
            arr[i++] = r_arr[k++];
        }
    }
}

void _merge_sort(int *arr, int lo, int hi)
{
    int mid = 0;

    // 左闭右开区间
    if (lo < hi - 1)
    {
        mid = (lo + hi) >> 1;
        _merge_sort(arr, lo, mid);
        _merge_sort(arr, mid, hi);
        myMerge(arr, lo, mid, hi);
    }
}

void merge_sort(int *arr, int n)
{
    _merge_sort(arr, 0, n);
}
// 函数顺序尽量满足调用顺序，先声明再调用，否则有警告！

/********************* end **********************************/


/********************* quick sort ***************************/
void _quick_sort(int *arr, int lo, int hi)
{
    int l, r, pivot;

    // 递归退出条件
    if (lo >= hi - 1)
    {
        return ;
    }

    l = lo;
    r = hi - 1;
    // 选择最右边位置作为基准点，改进算法：随机选择、三点取中间值...
    pivot = arr[r];

    while (l < r)
    {
        while (l < r && arr[l] <= pivot)
        {
            l++;
        }
        if (l < r)
        {
            arr[r--] = arr[l];
        }
        else
        {   // 排序完成
            break;
        }

        while (l < r && arr[r] >= pivot)
        {
            r--;
        }
        if (l < r)
        {
            arr[l++] = arr[r];
        }
        else
        {
            // 排序完成
            break;
        }
    }
    // 确定第一个排序位置
    arr[l] = pivot;

    // 分而治之
    _quick_sort(arr, lo, l);
    _quick_sort(arr, r+1, hi);

}

void quick_sort(int *arr, int n)
{
    _quick_sort(arr, 0, n);
}

/********************* end **********************************/


/********************* heap sort ****************************/
// 求左孩子 优化：定义为宏函数/内联函数
int get_lchild(int i)
{
    return 2 * i + 1;
}

void heap_filter(int *arr, int pivot, int n)
{
    int i = pivot;
    int lchild = 0;
    int rchild = 0;
    int temp = 0;

    while (i < n)
    {
        lchild = get_lchild(i);
        rchild = lchild + 1;
        if (rchild <= n-1)  // 有右孩子的情况
        {
            // temp = (arr[lchild] < arr[rchild] ? arr[lchild] : arr[rchild])
            if (arr[lchild] < arr[rchild])
            {
                if (arr[i] > arr[lchild])
                {
                    temp = arr[i];
                    arr[i] = arr[lchild];
                    arr[lchild] = temp;
                    i = lchild; // 过滤下一层
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (arr[i] > arr[rchild])
                {
                    temp = arr[i];
                    arr[i] = arr[rchild];
                    arr[rchild] = temp;

                    i = rchild; // 过滤
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (lchild == n - 1)   // 只有左孩子的情况
            {
                if (arr[i] > arr[lchild])
                {
                    temp = arr[i];
                    arr[i] = arr[lchild];
                    arr[lchild] = temp;

                    i = lchild;
                }
            }

            break;  // 没有必要再继续了！
        }
    }
    // 百科有优化方法，非常巧妙！
}

void heap_sort(int *arr, int n)
{
    int i = 0;
    int temp = 0;

    while (n > 1)   // 一个元素的时候，不需要建堆！
    {
        // 建堆
        i = (n - 1) / 2;
        for (; i >= 0; i--)
        {
            heap_filter(arr, i, n);
        }
        temp = arr[--n];    // 取出最后一个元素，数组长度减1
        arr[n] = arr[0];    // 最小的元素放在末尾
        arr[0] = temp;
    }
}


/********************* end **********************************/


/********************* shell sort *****************************/
void shell_sort(int *arr, int n)
{

}

/********************* end **********************************/

#endif // MYDORT_
