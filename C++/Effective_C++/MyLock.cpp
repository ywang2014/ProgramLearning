/**
	借助C语言的API：
		lock()
		unlock()
	实现RALL，将资源管理放进类对象中
	
	禁止复制
*/
class MyLock{
	public:
		explicit MyLock(Mutex* pm) : mutexPtr(pm){
			lock(mutexPtr);
		}
		
		~MyLock(){
			unlock(mutexPtr);
		}
	
	private:
		Mutex *mutexPtr;
		
		// 禁止复制
		MyLock(MyLock &ml);
		operator=(MyLock &ml);
}

// test
Mutex m;	// 定义互斥信号量
{
	MyLock(&m);	// 加锁
	...
}	// 自动释放锁

