/**
	过滤器 filter
	
	从输入流读，基于输入流执行某些操作，产生一个输出流，产生一个最后的结果
	
	一个简单的框架
*/
class Filter{
public:
	class Retry{
	public:
		virtual const char *message(){ return 0; }
	};
	
	virtual void start(){}
	virtual int read() = 0;
	virtual void write(){}
	virtual void compute(){}
	virtual int result() = 0;
	
	virtual int retry(Retry &m){
		cerr << m.message() << '\n';
		return 2;
	}
	
	virtual ~Filter(){}
};


// 框架提供的主循环和初步错误处理机制
int main_loop(Filter *p){
	for (; ; ){
		try{
			p->start();
			while (p->read()){
				p->compute();
				p->write();
			}
			return p->result;
		}
		catch (Filter::Retry &m){
			if (int i = p->retry(m)){
				return i;
			}
		}
		catch (...){
			cerr << "Fatal filter error \n";
			return 1;
		}
	}
}


class My_filter : public Filter{
	istream &is;
	ostream &os;
	int nchar;

public:
	int read(){
		char ch;
		is.get(ch);
		return is.good();
	}
	
	void compute(){ nchar++; }
	int result(){
		os << nchar << " characters read\n";
		return 0;
	}
	
	My_filter(istream &ii, ostream &oo) : is(ii), os(oo), nchar(0){}
};


int main(){
	My_filter f(cin, cout);
	
	return main_loop(&f);
}