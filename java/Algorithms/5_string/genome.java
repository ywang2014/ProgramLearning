/**
	数据压缩方法打包方式
*/
public class Genome{
	public static void compress(){
		// TODO
	}
	
	public static void expand(){
		// TODO
	}
	
	public static void main(String[] args){
		if (args[0].equals("-")){
			compress();
		}
		if (args[0].equals("+")){
			expand();
		}
	}
}