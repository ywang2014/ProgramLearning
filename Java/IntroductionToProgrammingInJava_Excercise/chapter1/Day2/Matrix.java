package Day2;

public class Matrix
{
	private int row;
	private int column;
	public int[][] mat;
	
	public Matrix(int size)
	{
		this.row = size;
		this.column = size;
		
		mat = new int[this.row][this.column];
		init();
	}
	
	public Matrix(int row, int column)
	{
		this.row = row;
		this.column = column;
		
		mat = new int[this.row][this.column];
		init();
	}
	
	public void init()
	{
		for (int i = 0; i < this.row; i++)
		{
			for (int j = 0; j < this.column; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	
	public int getRow()
	{
		return this.row;
	}
	
	public int getColumn()
	{
		return this.column;
	}
	
	public Matrix add(Matrix a, Matrix b)
	{
		int rows = a.getRow();
		int columns = a.getColumn();
		
		Matrix result = new Matrix(rows, columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result.mat[i][j] = a.mat[i][j] + b.mat[i][j];
			}
		}
		
		return result;
	}
	
	public Matrix product(Matrix a, Matrix b)
	{
		int rows = a.getRow();
		int columns = b.getColumn();
		int bRow = b.getColumn();
		
		Matrix result = new Matrix(rows, columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				for (int k = 0; k < bRow; k++)
				{
					result.mat[i][j] = a.mat[i][k] * b.mat[k][j];
				}
			}
		}
		
		return result;
	}
}
