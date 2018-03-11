/**
	今日头条一面：
		写一个快速排序
		
	泛型：怎么用？
		上界：extend
		下界：supper
		
	呼叫中心
	Java、Python
	大数据分析、数据挖掘
	
	TCP了解吗？
		三次握手
		四次挥手
		
*/
void quickSort(int *arr, int n){
    if (arr == nullptr || n < 1){
        return ;    // invalid parameter
    }
    quickSort(arr, 0, n-1);
}

void qucikSort(int *arr, int low, int high){
    if (low >= high){
        return ;
    }
    int povid = arr[high];
    int l = low;
    int h = high;
    while (l < h){
        for (l < h && arr[l] <= povid){
            l++;
        }
        if (l < h && arr[l] > povid){
            arr[h--] = arr[l];
        }
        for (l < h && arr[h] > povid){
            h--;
        }
        if (l < h && arr[h] < povid){
            arr[l++] = arr[h];
        } 
    }
    arr[l] = povid;
    quickSort(arr, low, l-1);
    quickSort(arr, l+1, high);
}

int main(){
    int arr[5] = {5,4,3,2,1};
    quickSort(arr, 5);
    for (int i = 0; i < 5; i++){
        printf(arr[i]);
    }
}