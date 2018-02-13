/**
	偶数二面算法题目：
*/
// 删除字符串中的指定字符
void removeChar(char *str, char deletedChar){
	if (str == nullptr){
		return nullptr;	// invalid parameter
	}
	int len = strlen(str);
	char *p = str;
	char *q = str;
	while (*q != '\0'){
		if (*q != deletedChar){
			*p++ = *q;
		}
		p++;
	}
	*p = '\0';
}

/**
	为了方便起见，约定：初始化建空队时，令
      front=rear=0,
  当队空时：front=rear
  当队满时：front=rear 亦成立
  因此只凭等式front=rear无法判断队空还是队满。  有两种方法处理上述问题：
    （1）另设一个标志位以区别队列是空还是满。
    （2）少用一个元素空间，约定以“队列头指针front在队尾指针rear的下一个位置上”作为队列“满”状态的标志。即：
  队空时： front=rear
  队满时： (rear+1)%maxsize=front

  front指向队首元素，rear指向队尾元素的下一个元素。
*/

// 数组实现循环队列
class Queue{
	int *buffer;
	int low = 0;
	int high = 0; 
	int size = 100;
	int count = 0;
	
	Queue(){
		buffer = new int[size];
	}
	
	int dequeue(){
		if (count != 0){
			int value = buffer[low];
			low = (low + 1) % 100;
			count--;
			return value;
		}
		error();
	}
	
	void enqueue(int value){
		if (count < size){
			buffer[high] = value;
			high = (high + 1) % 100;
			count++;
		}
		error();
	}
}

// 数组实现循环队列
class Queue{
	int *buffer;
	int low = 0;
	int high = 0; 
	int capacity = 100;
	
	Queue(){
		buffer = new int[capacity];
	}
	
	// size 方法有些问题：先增加满，全部删除！low = 0 high = capacity, 实际是空的
	int size(){
		if (high >= low){
			return high - low;
		}
		return high + capacity - low;
	}
	
	bool isEmpty(){
		return low == high;
	}
	
	bool isFull(){
		// 空一个元素空间不使用
		return low == (high + 1) % capacity;
	}
	
	int dequeue(){
		if (isEmpty()){
			error();
		}
		int value = buffer[low];
		buffer[low] = nullptr;
		low = (low + 1) % capacity;
		return value;
	}
	
	void enqueue(int value){
		if (isFull()){
			error();
		}
		buffer[high] = value;
		high = (high + 1) % capacity;
	}
}