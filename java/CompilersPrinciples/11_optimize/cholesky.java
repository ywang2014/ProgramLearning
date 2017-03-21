/**
	Cholesky分解
*/
void cholesky(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i-1; j++){
			for (int k = 1; k <= j-1; k++){
				x[i, j] = x[i, j] - x[i, k] * x[j, k];
			}
			x[i, j] = x[i, j] / x[j, j];
		}
		for (int m = 1; m <= i-1; m++){
			x[i, i] = x[i, i] - x[i, m] * x[i, m];
		}
		x[i, i] = sqrt(x[i, i]);
	}
}