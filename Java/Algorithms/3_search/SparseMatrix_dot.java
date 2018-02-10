/**
	稀疏矩阵和向量的乘法
*/
public class SparseMatrix{
	public static void main(String[] args){
		SparseVector[] a;
		a = new SparseVector[N];
		double[] x = new double[N];
		double[] res = new double[N];
		
		// initialize
		
		for (int i = 0; i < N; i++){
			res[i] = a[i].dot(x);
		}
	}
}


////////////////////////////////////////////////////////////////////////////////
public class SparseMatrix{
	
	private SparseVector[] a;
	private int N;
	
	public SparseMatrix(){
		this.SparseMatrix(10000);
	}
	
	public SparseMatrix(int n){
		this.N = n;
		a = new SparseVector[n];
	}
	
	public init(){
		// TODO
	}
	
	public double[] dot(double[] x){
		double[] res = new double[N];
		for (int i = 0; i < N; i++){
			res[i] = a[i].dot(x);
		}
		return res;
	} 
	
}