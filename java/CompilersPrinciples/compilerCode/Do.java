/**
	Do
*/
package inter;

import symbols.*;

public class Do extends Stmt{
	Expr expr;
	Stmt stmt;
	
	public Do(){
		expr = null;
		stmt = null;
	}
	
	public void init(Expr e, Stmt s){
		expr = e;
		stmt = s;
		if (expr.type != Type.Bool){
			expr.error("boolean required in do while");
		}
	}
	
	public void gen(int b, int a){
		after = a;
		int label = newlabel();
		stmt.gen(b, label);
		emitlabel(label);
		expr.jumping(b, 0);
	}
}