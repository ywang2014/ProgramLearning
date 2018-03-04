/**
	智分科技（NewsJet）面试算法题：
	
	牺牲空间，实现稳定的快速排序
	
	/////////////////////////////////////////
	1.项目问题，简单介绍项目，为什么存在性能问题，数据量等。如何解决
	2.MySQL索引：原理（MyISAM、InnoDB）联合索引原理，最左前缀索引
	3.数据结构和算法：排序算法有哪些，性能、稳定性等等。
	4.编程：写一个稳定的快速排序。
	5.设计模式：单例模式和工厂模式。单例模式特点，实现方式(恶汉模式、懒汉模式)，如何解决多线程问题，为什么会有多线程问题。volitale等。
*/

void quickSort(int *arr, int n){
    if (arr == nullptr || n < 1){
        return ;    // invalid parameters
    }
    quickSort(arr, 0, n);
}

void quickSort(int *arr, int low, int high){
    if (low >= high){
        return ;
    }
    int len = high - low;
    int *bigData = new int[len];
    int *smallData = new int[len];
    int pivot = arr[high-1];
    int smallIndex = 0;
    int bigIndex = 0;
    for (int i = low; i < high-1; i++){
        if (pivot < arr[i]){
            bigData[bigIndex++] = arr[i];
        } else {
			// 因为轴点是最后一个，所以等于放在下面
            smallData[smallIndex++] = arr[i];
        }
    }
    for (int i = 0; i < smallIndex; i++){
        arr[low+i] = smallData[i];
    }
    arr[low+smallIndex] = pivot;
    for (int i = 0; i < bigIndex; i++){
        arr[low+smallIndex+i] = bigData[i];
    }
    delete[] bigData;
    delete[] smallData;
    quickSort(arr, low, smallIndex);
    quickSort(arr, smllIndex+1, high);
}
