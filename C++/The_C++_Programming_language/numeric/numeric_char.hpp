/**
	numeric_limits 的char专门化
*/
class numeric_limits<char>{
public:
	static const bool is_specialized = true;
	
	static const int digits = 7;	// 二进制位数，不包括符号位
	
	static const bool is_signed = true;
	static const bool is_integer = true;
	
	static char min() throw() { return -128; }	
	static char max() throw() { return 127; }
	
	// 与char无关的声明
};