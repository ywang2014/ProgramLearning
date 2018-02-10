/**
	Id
*/
package inter;

import lexer.*;
import symbols.*;

public class Id extends Expr{
	public int offset;
	
	public Id(Word id, Type t, int b){
		super(id, t);
		offset = b;
	}
}