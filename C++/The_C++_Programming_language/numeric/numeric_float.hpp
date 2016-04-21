/**
	numeric_limits 的float专门化
*/
class numeric_limits<float>{
public:
	static const bool is_specialized = true;
	
	static const int radix = 2;		// 指数的基数
	static const int digits = 24;	// 尾数按照基数的位数
	static const int digits10 = 6;	// 尾数按照十进制的位数
	
	static const bool is_signed = true;
	static const bool is_integer = false;
	
	static const bool is_exact = false;	// 是否精确的
	
	static float min() throw() { return 1.17549435E-38F; }
	static float max() throw() { return 3.40282347E+38F; }
	
	static float epsilon() throw() { return 1.1920920E-07F; }
	static float round_error() throw() { return 0.5F; }
	
	static float infinity() throw() { return /* 某个值 */; }
	static float quiet_NaN() throw() { return /* 某个值 */; }
	static float signaling_NaN() throw() { return /* 某个值 */; }
	static float denorm_min() throw() { return min(); }
	
	static const int min_exponent = -125;
	static const int min_exponent10 = -37;
	static const int max_exponent = +128;
	static const int max_exponent10 = +38;
	
	static const bool has_infinity = true;
	static const bool has_quiet_NaN = true;
	static const bool has_signaling_NaN = true;
	static const float_denorm_loss = false;
	
	static const bool is_iec559 = true;	// 符合IEC-559
	static const bool is_bounded = true;
	static const bool is_modulo = false;
	static const bool traps = true;
	static const bool tinyness_before = true;
	
	static const float_round_style round_style = round_to_nearest;	// enum 
};