package Day1;

public class Binary
{
	public static void main(String[] args)
	{
		int n = Integer.parseInt(args[0]);
		
		String bin = " ";
		
		while (n > 0)
		{
			bin += n % 2;	// 顺序存储 2 的余数
			n /= 2;			// 不断地右移
		}
		
		System.out.println("Decimal: " + Integer.parseInt(args[0]));
		
		// 逆序输出，即可得2进制数。所以使用 StringBuffer
		StringBuffer sb = new StringBuffer(bin);
		System.out.println("Binary: " + sb.reverse().toString());
	}
}
