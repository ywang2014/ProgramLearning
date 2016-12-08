/**
	利用字符串产生的程序，代表字符串本身，实现数据压缩
	
	"被压缩后的"一段一百万比特的数据流
*/
public class RandomBits{
	public static void main(String[] args){
		int x = 1111;
		for (int i = 0; i < 1000000; i++){
			x = x * 314159 + 218281;
			BinaryStdOut.write(x > 0);
		}
		BinaryStdOut.close();
	}
}