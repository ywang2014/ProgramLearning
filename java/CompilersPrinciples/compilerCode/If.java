/**
	If
*/
package inter;

import symbols.*;

public class If extends Stmt{
	Expr expr;
	Stmt stmt;
	
	public If(Expr e, Stmt s){
		expr = e;
		stmt = s;
		if (expr.type != Type.Bool){
			expr.error("boolean required in if");
		}
	}
	
	public void gen(int b, int a){
		int label = newlabel();
		expr.jumping(0, a);	// 为真时，直接穿过控制流；为假时，转向a
		emitlabel(label);
		stmt.gen(label, a);
	}
}