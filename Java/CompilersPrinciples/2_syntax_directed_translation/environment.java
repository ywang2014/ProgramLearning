/**
	类Environment实现的链接符号表
*/
package symbols;

import java.util.*;

public class Environment{
	private Hashtable table;
	protected Environment prev;
	
	public Environment(Environment p){
		table new Hashtable();
		prev = p;
	}
	
	public void put(String s, Symbol sym){
		table.put(s, sym);
	}
	
	public Symbol get(String s){
		for (Environment e = this; e != null; e = e.prev){
			Symbol found = (Symbol)(e.table.get(s));
			if (found != null){
				return found;
			}
		}
		return null;
	}
}