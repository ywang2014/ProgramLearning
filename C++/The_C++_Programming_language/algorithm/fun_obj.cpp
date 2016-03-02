/**
	函数对象
*/
template<typename T>
class Sum
{
	private:
		T result;
	public:
		Sum(T i = 0) : result(i) {}	// 初始化
		void operator()(T x) {result += x; }	// 累加
		T result() const { return result; }		// 返回和数
};

void f(list<double>& ls)
{
	Sum<double> sum;
	sum = for_each(ls.begin((), ls.end(), sum);	// 对表中每一个元素调用sum()函数对象
	cout << "the sum is " << sum.result() << endl;
}