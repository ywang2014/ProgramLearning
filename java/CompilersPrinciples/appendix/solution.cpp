/**
	寻找线性独立解
	
	源代码还不完善，存在很多漏洞
	核心思想：
		高斯消元法
*/
void transposedMatrix(int **A, int **m, int row = n, int col = n){
	// 默认矩阵属于n*n的
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			m[i][j] = A[j][i];
		}
	}
}

void unitize(int **m, int d = n){
	for (int i = 0; i < d; i++){
		for (int j = 0; j < d; j++){
			if (i == j){
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	}
}

void exchange(int **m, int r1, int r2, int col = n){
	for (int i = 0; i < col; i++){
		int temp = m[r1][i];
		m[r1][i] = m[r2][i];
		m[r2][i] = temp;
	}
}

// 主函数
void solution(int **A, int *x){
	int **m = new int*[n];
	for (int i = 0; i < n; i++){
		m[i] = new int[n];
	}
	transposedMatrix(A, m);
	unitize(B);
	int r0 = 1;
	int c0 = 1;
	
	while (true){
		// 1.将M转化为对角线元素为正的对角矩阵
		int r1 = r0;
		int c1 = c0;
		int r = 0;
		int c = 0;
		while (existUnzero(m[r][c])){
			if (r >= r1 && c >= c1){
				if (m[r1][c1] < 0){
					m[r1] = -1 * m[r1];
					b[r1] = -1 * B[r1];
				}
				for (int row = r0; row <= n; row++){
					if (row != r1 && m[row][c1] != 0){
						int u = -(m[row][c1] / m[r1][c1])
						m[row] = m[row] + u * m[r1];
						B[row] = B[row] + u * B[r1]
					}
				}
			}
			r1++;
			c1++;
		}
		
		// 2.找出第一个解
		if (如果存在一个非平凡解，比如Ki>0){
			for (int i = 0; i < r; i++){
				m[r] += K[i]*m[i];
			}
			NoMoreSoln = false;
		}
		else {
			NoMoreSoln = true;
		}
		
		// 3.使得M[r0:n-1][c0:m]>=0
		if (NoMoreSoln){
			for (int r = r1; r < n; r++){
				exchange(m, r, r0+r-r1);
				exchange(B, r, r0+r-r1);
			}
			rn = r0 + n - r1 + 1;
		}
		else {
			rn = n + 1;
			for (int col = c1; col <= m; col++){
				if (存在M[row][col]<0,使得row>=r0){
					if (存在M[r][col]>0,使得r>=r0){
						for (int row = r0; row < rn; row++){
							if (m[row][col] < 0){
								int u = -(m[row][col] / m[r][col]);
								m[row] = m[row] + u * m[r];
								B[row] = B[row] + u * B[r];
							}
						}
					}
					else {
						for (int row = rn-1; row >= r0; row--){
							if (m[row][col] < 0){
								rn = rn - 1;
								exchange(m, row, rn);
								exchange(B, row, rn);
							}
						}
					}
				}
			}
		}
		
		// 4.M[r0:rn-1][1:c0-1]>=0
		for (int row = r0; row < rn; row++){
			for (int col = 1; col < c0; col++){
				if (m[rol][col] < 0){
					int u = -(m[row][col] / m[r][col]);
					m[row] = m[row] + u * m[r];
					B[row] = B[row] + u * B[r];
				}
			}
		}
		
		// 5.如果需要，对M[rn:n]中的各行重复处理
		if (NoMoreSoln || rn > n || rn == r0){
			// 从B中删除rn到n各行
			erase(B, rn, n);
			return B;
		}
		else {
			cn = m + 1;
			for (int col = m; col >= 1; col--){
				if (不存在M[r][col]>0,使得r<rn){
					cn = cn - 1;
					exchangeCol(m, col, cn);
				}
			}
			r0 = rn;
			c0 = cn;
		}
	}
}