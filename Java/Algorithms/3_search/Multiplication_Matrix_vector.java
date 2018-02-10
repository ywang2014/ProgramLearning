/**
	矩阵和向量乘法
*/
public class Multiplication{
	public static void main(String[] args){
		double[][] matrix = new double[N][N];
		double[] vector = new double[N];
		double[] res = new double[N];
		
		// initialize
		
		for (int i = 0; i < N; i++){
			double sum = 0.0;
			for (int j = 0; j < N; j++){
				sum += matrix[i][j] * vector[j];
			}
			res[i] = sum;
		}
	}
}