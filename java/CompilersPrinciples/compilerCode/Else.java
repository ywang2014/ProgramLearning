/**
	Else
*/
package inter;

import symbols.*;

public class Else extends Stmt{
	Expr expr;
	Stmt stmt1;
	Stmt stmt2;
	
	public Else(Expr e, Stmt s1, Stmt s2){
		expr = e;
		stmt1 = s1;
		stmt2 = s2;
		if (expr.type != Type.Bool){
			expr.error("boolean required in if");
		}
	}
	
	public void gen(int b, int a){
		int label1 = newlabel();
		int label2 = newlabel();
		expr.jupming(0, label2);	// 为真时控制流穿越到stmt1
		
		emitlabel(label1);
		stmt1.gen(label1, a);
		emit("goto L" + a);
		
		emitlabel(label2);
		stmt2.gen(label2, a);
	}
}