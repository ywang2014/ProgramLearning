/**
	类If伪代码
*/
class If extends Stmt{
	Expr E;
	Stmt S;
	
	public If(Expr x, Stmt y){
		E = x;
		S = y;
		after = newlabel();
	}
	
	public void gen(){
		Expr n = E.rvalue();
		emit("ifFalse" + n.toString() + "goto" + after);
		S.gen();
		emit(after + ":");
	}
}
