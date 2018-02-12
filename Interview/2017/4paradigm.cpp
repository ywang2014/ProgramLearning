/**
	第四范式，第一轮面试算法题
		1.输出数组的第k大的数字，数组长度为n。
		2.写SQL语句
*/

int findKthNumber(int *array, int n, int k){
    if (array == null || n < 1 || k < 1 || k > n){
        return -1;
    }
	
	buildBigHeap();
	int kthNumber = 0;
	for (int i = 0; i < k; i++){
		kthNumber = array[0];
		swap(arr, 0, n-1);
		n--;
		downFilter(arr, n, 0);
	}
	return kthNumber;
}

void buildBigHeap(int *array, int n){
    for (int i = n/2; i >= 0; i--){
		downFilter(array, n, i);
    }
}

// 上虑非常麻烦，不容易处理 左右孩子的问题
void upFilter(int *arr, int n, int i){
    int parentNodeIndex = findParent(i);
    if (parentNodeIndex >= 0 || arr[i] > arr[parentNodeIndex]){
        swap(arr, i, parentNodeIndex);
    }
}

void downFilter(int *arr, int n, int i){
    int leftChildIndex = findLeftChild(i);
    int rightChildIndex = findRightChild(i);
    if (leftChildIndex >= n){
        return ;
    } else if (rightChildIndex >= n){
		if (arr[i] < arr[leftChildIndex]){
		swap(arr, i, leftChildIndex);
            downFilter(arr, n, leftChildIndex);
		}
	} else if (arr[i] < arr[leftChildIndex] || arr[i] < arr[rightChildIndex]){
        if (arr[leftChildIndex] <= arr[rightChildIndex]){
            swap(arr, i, leftChildIndex);
            downFilter(arr, n, leftChildIndex);
        } else {
            swap(arr, i, rightChildIndex);
            downFilter(arr, n, rightChildIndex);
       }
    }
}

// swap array[a] and array[b]
void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


int findParent(int i){
    return (i - 1) / 2;
}

int findLeftChild(int i){
    return 2 * i + 1;
}

int findRightChild(int i){
    return 2 * i + 2;
}



Q1. 给出两张表，表一为样本表，格式为 client_id, prod_id,current_time,label  表二为产品购买记录，格式为 client_id, prod_id, purchase_time,prod_start_time, prod_expire_time, trx_amount 
要求：在表一的基础上增加两列，当前持有产品数，当前持有产品金额
# SQL
 
select virtual_t.client_id, virtual_t.current_time, count(virtual_t.*), sum(virtual_t.trx_amount) from (select t1.client_id, t1.current_time, t2.trx_amount from t2 left join t1 where t2.client_id = t1.client_id and t2.purchase_time <= t1.current_time and t1.current_time <= t2.prod_expire_time)virtual_t group by virtual_t.client_id, virtual_t.current_time






