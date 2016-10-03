/**
	自定义operator new operator delete
*/
static const int signature = 0xDEADBEEF;
typedef unsigned char Byte;

void *operator new(std::size_t size) throw(std::bad_alloc){
	using namespace std;
	// 增加大小，添加两个signatures
	size_t realSize = size + 2 * sizeof(int);
	
	void *pMem = malloc(realSize);
	if (!pMem){
		throw bad_alloc();
	}
	
	*(static_cast<int*>(pMem)) = signature;
	*(reinterpret_cast<int*>(static_cast<Byte*>(pMem) + realSize - sizeof(int))) = signature;
	
	return static_cast<Byte*>(pMem) + sizeof(int);
}