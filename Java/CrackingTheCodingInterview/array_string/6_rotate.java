/**
	给定一幅由n*n的矩阵表示的图像，其中每个像素的大小为4字节，请编写一个函数，将图像旋转90度。
	不占用额外内存空间能否做到？
*/
public void rotate(int[][] matrix, int n){
	for (int layer = 0; layer < n / 2; layer++){
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first; i < last; i++){
			int offset = i - first;
			int top = matrix[first][i];
			// 左到上
			matrix[first][i] = matrix[last - offset][first];
			// 下到左
			matrix[last - offset][first] = matrix[last][last - offset];
			// 右到下
			matrix[last][last - offset] = matrix[i][last];
			// 上到右
			matrix[i][last] = top;
		}
	}
}