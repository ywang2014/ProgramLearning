/**
	编写一个算法，若M*N矩阵中，某个元素为0，则将其所在的行与列清零
*/
public void setZeros(int[][] matrix){
	boolean rowHasZero = new boolean[matrix.length];
	boolean columnHasZero = new boolean[matrix[0].length];
	
	for (int i = 0; i < matrix.length; i++){
		for (int j = 0; j < matrix[0].length; j++){
			if (matrix[i][j] == 0){
				rowHasZero[i] = true;
				columnHasZero[j] = true;
			}
		}
	}
	
	// for (int i = 0; i < rowHasZero.length; i++){
		// if (rowHasZero[i]){
			// for (int j = 0; j < matrix[0].length; j++){
				// matrix[i][j] = 0;
			// }
		// }
	// }
	// for (int j = 0; j < columnHasZero.length; j++){
		// if (columnHasZero[j]){
			// for (int i = 0; i < matrix.length; i++){
				// matrix[i][j] = 0;
			// }
		// }
	// }
	for (int i = 0; i < matrix.length; i++){
		for (int j = 0; j < matrix[0].length; j++){
			if (rowHasZero[i] || columnHasZero[j]){
				matrix[i][j] = 0;
			}
		}
	}
}