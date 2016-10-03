/**
	资源管理类 -- RALL
*/
class NewHandlerHolder{
	public:
		explicit NewHandlerHolder(std::new_handler p) : handler(p) {}
		~NewHandlerHolder(){
			std::set_new_handler(handler);	// 析构时，回复全局的new_handler
		}
		
	private:
		std::new_handler handler;
		
		NewHandlerHolder(const NewHandlerHolder&);				// 禁止拷贝构造
		NewHandlerHolder& operator=(const NewHandlerHolder&);	// 禁止拷贝赋值
};


class Widget{
	public:
		static std::new_handler set_new_handler(std::new_handler ph) throw();
		static void *operator new(std::size_t size) throw(std::bad_alloc);
	private:
		static std::new_handler currentHandler;
};

std::new_handler Widget::currentHandler = 0;	// static成员，初始化

std::new_handler Widget::set_new_handler(std::new_handler ph) throw(){
	std::new_handler oldHandler = currentHandler;
	currentHandler = ph;
	return oldHandler;
}

void Widget::operator new(std::size_t size) throw(std::bad_alloc){
	NewHandlerHolder h(std::set_new_handler(currentHandler));	// 设置new_handler，并赋值给h
	return ::operator new(size);	// 全局的new
}

// demo
void outOfMem();

Widget::set_new_handler(outOfMem);	// std::set_new_handler()

Widget *pw = new Widgrt();
std::string *ps = new std::string();
