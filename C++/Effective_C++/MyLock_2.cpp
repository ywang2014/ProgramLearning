/**
	借助C语言的API：
		lock()
		unlock()
	实现RALL，将资源管理放进类对象中
	
	使用引用计数，解决复制问题
*/
class MyLock{
	public:
		explicit MyLock(Mutex* pm) : mutexPtr(pm, unlock){
			lock(mutexPtr.get());
		}
		
		// default destructor
	
	private:
		std::shared_ptr<Mutex> mutexPtr;	// shared_ptr指定第二个参数，析构函数调用unlock，而不是删除对象
		
}

// test
Mutex m;	// 定义互斥信号量
{
	MyLock(&m);	// 加锁
	...
}	// 自动释放锁

