/**
	Break
*/
package inter;

import lexer.*;
import symbols.*;

public class Break extends Stmt{
	Stmt stmt;
	
	public Break(){
		if (Stmt.Enclosing == Stmt.null){
			error("unenclosed break");
		}
		stmt = Stmt.Enclosing;
	}
	
	public void gen(int b, int a){
		emit("goto L" + stmt.after);
	}
}