/**
	标准allocator
*/
template<typename T>
class std::allocator{
	public:
		typedef T value_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		
		typedef T *pointer;
		typedef const T *const_pointer;
		
		typedef T &reference;
		typedef const T &const_reference;
		
		pointer address(reference r) const {
			return &r;
		}
		const_pointer address(const_reference r) const {
			return &r;
		}
		
		
		allocator() throw();
		template<class U> allocator(const allocator<U>&) throw();
		~allocator() throw();
		
		pointer allocate(size_type n, allocator<void>::const_pointer hint = 0);
		void deallocate(pointer p, size_type n);
		
		void construct(pointer p, const T& val) {
			new(p) T (val);	// 用val初始化p
		}
		void destroy(pointer p){
			p->~T();	// 销毁*p，不释放
		}
		
		size_type max_size() const throw();
		
		template<class U> struct rebind{
			typedef allocator<U> other;
		}; // typedef allocator<U> other
};

template<class T> bool operator==(const allocator<T> &, const allocator<T> &) throw();
template<class T> bool operator!=(const allocator<T> &, const allocator<T> &) throw();


// 专门化	通用指针类型：allocator<void>::pointer 		(void *)
template<> class allocator<void>{
	public:
		typedef void *pointer;
		typedef const void *const_pointer;
		// 没有reference
		
		typedef void value_type;
		
		template <class U> struct rebind{
			typedef allocator<U> other;
		};	// typedef allocator<U> other 
}

// rebind类型作用
typedef typename A::template rebind<Link>::other Link_alloc;
typedef typename A::rebind<Link>::other Link_alloc;
// 如果A是一个allocator，那么rebind<Link>::other 就被定义为代表 allocator<Link>
typedef allocator<Link> Link_alloc;		// rebind实现是间接表述方式
// rebind实现为了隐藏allocator
