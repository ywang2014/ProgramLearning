template<class T> class List
{
	private:
		struct Link	// 使用数据结构保存元素的踪迹
		{
			T value;
			Link* next;
		};
		
		struct Chunk
		{
			enum {chunk_size = 15};
			Link v[chunk_size];
			Chunk* next;
		};
		
		Chunk* allocated;
		Link* free;
		Link* get_free();
		Link* head;
	
	public:
		class Underflow{};	// 异常类
		
		void insert(T);
		T get();
		// ...
};

template<class T> void List<T>::insert(T val)
{
	Link* lnk = get_free();
	lnk->value = value;
	lnk->next = head;
	head = lnk;
}

template<class T> List<T>::Link* List<T>::get_free()
{
	if (free == 0)
	{
		// 分配一个新快，将其中所有的Link放入自由表
	}
	Link* p = free;
	free = free->next;
	return p;
}

template<class T> T List<T>::get()
{
	if (head == 0)
	{
		throw Underflow();
	}
	
	Link* p = head;
	head = p->next;
	p->next = free;
	free = p;
	return p->value;
}