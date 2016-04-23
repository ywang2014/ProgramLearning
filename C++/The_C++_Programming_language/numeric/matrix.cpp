/**
	实现
*/
// 迭代器的运用
// 返回i行，整行的迭代器
inline Slice_iter<double> Matrix::row(size_t, i){
	// Slice_iter的构造函数
	return Slice_iter<double>(v, slice(i, column, row));
}

inline Cslice_iter<double> Matrix::row(size_t i) const{
	return Cslice_iter<double>(v, slice(i, column, row);
}

// 返回i列，整列的迭代器
inline Slice_iter<double> Matrix::column(size_t i){
	return Slice_iter<double>(v, slice(i * column, column, 1);
}

inline Cslice_iter<double> Matrix::column(size_t i) const{
	return Cslice_iter<double>(v, slice(i * column, column, 1);
}


Matrix::Matrix(size_t x, size_t y){
	assert(x > 0 && y > 0);
	
	row = x;
	column = y;
	v = new valarray<double>(x * y);
}

double &Matrix::operator()(size_t x, size_t y){
	return row[x][y];
}

double mul(Cslice_iter<double> &v1, const valarray<double> &v2){
	double res = 0;
	for (int i = 0; i < v1.size(); i++){
		res += v1[i] * v2[i];
	}
	
	return res;
}

valarray<double> operator*(const Matrix &m, const valarray<double> &v){
	valarray<double> res(m.dim1());
	for (int i = 0; i < m.dim1(); i++){
		res[i] = mul(m.row(i), v);
	}
	
	return res;
}

Matrix &Matrix::operator*=(double d){
	(*v) *= d;
	
	return *this;
}