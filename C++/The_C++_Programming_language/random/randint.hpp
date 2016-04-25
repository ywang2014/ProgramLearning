/**
	随机数生成器
*/
// 均匀分布，32位long
class Randint{
	unsigned long randx;
public:
	Randint(long s = 0){ randx = s; }
	void seed(long s){ randx = s; }
	
	// 魔幻数，选用32位long中的31位
	long abs(long x){ return x & 0x7fffffff; }
	static double max(){ return 2147483648.0; }
	long draw(){ return randx = randx * 1103515245 + 12345; }
	
	double fdraw(){ return abs(draw()) / max(); }	// [0, 1]
	
	long operator()(){ return abs(draw()); }
};


// 均匀分布，[0, n[
class Urand : public Randint{
	long n;
public:
	Urand(long nn){ n = nn; }
	long operator()(){ 
		long r = n * fdraw();
		return (r == n) ? n - 1 : r;
	}
};


// 指数分布随机数生成器
class Erand : public Randint{
	long mean;
public:
	Erand(long m){ mean = m; }
	long operator()(){ return -mean * log((max() - draw()) / max() + 0.5); }
}