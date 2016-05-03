/**
	堆结构的实现
	
	数组v存储元素
	
	建堆操作：
		首先将所有元素按照初始顺序填充到一个完全二叉树中
		从“最后一个非终端节点”开始，调用siftdown方法，调整堆的结构，直到根节点为止
*/

inline int Heap::leftChild(int i){
	return 2 * i;
}

inline int Heap::rightChild(int i){
	return 2 * i + 1;
}

inline int Heap::parent(int i){
	return i / 2;
}

inline int Heap::value(int i){
	return v[i];
}

inline int Heap::isNull(int i){
	return (i < 1 || i > n);
}

inline void Heap::swap(int i, int j){
	int v_i = v[i];
	v[i] = v[j];
	v[j] = v_i;
}


void Heap::siftup(int pos){
	// i > 1说明有父亲，v[i] < v[i/2]说明违反了有序性，需要交换
	for (int i = pos; i > 1 && v[i] < v[i/2]; i = i / 2){
		swap(i, i/2);
	}
}


void Heap::siftdown(int pos){
	for (int i = 1; i < pos; ){
		int child = leftChild(i);
		if (isNull(child)){
			break;
		}
		if (!isNull(child + 1)){
			if (v[child] > v[child + 1]){
				child++;
			}
		}
		
		if (v[i] > v[child]){
			swap(i, child);
			i = child;
		}
		else{
			break;
		}
	}
}

void Heap::insert(int t){
	if (n >= maxsize){
		return ; // range_error
	}
	x[++n] = t;
	siftup(n);
}