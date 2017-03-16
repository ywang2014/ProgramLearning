/**
	Stmt
*/
package inter;

public class Stmt extends Node{
	public Stmt(){
		// 子类实现
	}
	
	public static Stmt Null = new Stmt();
	
	// 参数：语句开始处的标号，语句下一条指令的标号
	public void gen(int b, int a){
		
	}
	
	int after = 0;	// 保存语句下一条指令的标号
	
	public static Stmt Enclosing = Stmt.Null;	// 用于break语句
}