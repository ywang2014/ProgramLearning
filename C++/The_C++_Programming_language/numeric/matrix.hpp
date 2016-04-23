/**
	矩阵类
	
	借助于valarray, slice实现的矩阵
*/
class Matrix{
	valarray<double> *v;
	size_t row;
	size_t column;
	
public:
	Matrix(size_t x, size_t, y);	// 无默认构造函数
	Matrix(const Matrix &);
	Matrix& operator=(const Matrix &);
	~Matrix();
	
	size_t size() const { return row * column; }
	size_t dim1() const { return row; }
	size_t dim2() const { return column; }
	
	Slice_iter<double> row(size_t i);
	Cslice_iter<double> row(size_t i) const;
	Slice_iter<double> column(size_t i);
	Slice_iter<double> column(size_t i) const;
	
	double &operator()(size_t x, size_t y);
	double operator()(size_t x, size_t y) const;
	
	Slice_iter<double>operator()(size_t i) { return row(i); }
	Cslice_iter<double>operator()(size_t i) const { return row(i); }
	Slice_iter<double>operator[](size_t i) { return row(i); }
	Cslice_iter<double>operator[](size_t i) const { return row(i); }
	
	Matrix &operator*=(double);
	
	valarray<double> &array() { return *v; }
};