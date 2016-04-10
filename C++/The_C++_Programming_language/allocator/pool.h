/**
	Pool interface
	
	池分配器，界面不完美
	快速分配和释放
*/
class Pool{
	struct Link{
		Link *next;
	};
	
	struct Chunk{
		enum { size = 8 * 1024 - 16; };	// 8k略小，用于对齐
		char mem[size];	// 分配区在前面，严格对齐
		Chunk *next;
	};
	
	Chunk *chunks;
	const unsigned int esize;
	Link* head;
	
	Pool(Pool &);	// 防止复制，private
	void operator=(Pool &);	// 防止复制，private
	
	void grow();

public:
	Pool(unsigned int n);
	~Pool();
	
	void *alloc();
	void free(void *p);
}