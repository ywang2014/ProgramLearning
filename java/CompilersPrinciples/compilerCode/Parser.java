/**
	Parser
*/
package parser;

import java.io.*;
import lexer.*;
import symbols.*;
import inter.*;

public class Parser{
	private Lexer lex;
	private Token look;
	Env top = null;
	int used = 0;
	
	public Parser(Lexer l) throws IOException{
		lex = l;
		move();
	}
	
	void move() throws IOException{
		look = lex.scan();
	}
	
	void error(String s){
		throw new Error("near line " + lex.line + ": " + s);
	}
	
	void match(int t) throws IOException{
		if (look.tag == t){
			move();
		}
		else {
			error("syntax error");
		}
	}
	
	public void program() throws IOException{
		Stmt stmt = block();	// ?
		int begin = stmt.newlabel();
		int after = stmt.newlabel();
		stmt.emitlabel(begin);
		stmt.gen(begin, after);
		stmt.emitlabel(after);
	}
	
	Stmt block() throws IOException{
		match('{');
		Env saveEnv = top;
		top = new Env(top);
		decls();	// ?
		Stmt stmt = stmts();
		match('}');
		top = saveEnv;
		return stmt;
	}
}
