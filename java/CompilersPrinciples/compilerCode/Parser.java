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
	
	void decls() throws IOException{
		while (look.tag == Tag.BASIC){
			Type t = type();
			Token tok = look;
			match(Tag.ID);
			match(';');
			
			Id id = new Id((Word)tok, t, used);
			top.put(tok, id);
			used = used + t.width;
		}
	}
	
	Type type() throws IOException{
		Type t = (Type)look;
		match(Tag.BASIC);
		if (look.tag != '['){
			return t;
		}
		else {
			return dims(t);
		}
	}
	
	Type dims(Type t) throws IOException{
		match('[');
		Token tok = look;
		match(Tag.NUM);
		match(']');
		
		if (look.tag == '['){
			t = dims(t);
		}
		else {
			return new Array(((Num)tok).value, t);
		}
	}
	
	Stmt stmts() throws IOException{
		if (look.tag == '}'){
			return Stmt.Null;
		}
		else {
			return new Seq(stmt(), stmts());
		}
	}
	
	Stmt stmt() throws IOException{
		Expr expr;
		Stmt s, s1, s2;
		Stmt savedStmt;
		switch (look.tag){
			case ';':
				move();
				return Stmt.Null;
			case Tag.IF:
				match(Tag.IF);
				match('(');
				expr = bool();
				match(')');
				s1 = stmt();
				if (look.tag != Tag.ELSE){
					return new If(expr, s1);
				}
				match(Tag.ELSE);
				s2 = stmt();
				return new ELSE(expr, s1, s2);
			case Tag.WHILE:
				While whilenode = new While();
				savedStmt = Stmt.Enclosing;
				Stmt.Enclosing = whilenode;
				match(Tag.WHILE);
				match('(');
				expr = bool();
				match(')');
				s1 = stmt();
				whilenode.init(expr, s1);
				Stmt.Enclosing = savedStmt;
				return whilenode;
			case Tag.DO:
				Do donode = new Do();
				savedStmt = Stmt.Enclosing;
				Stmt.Enclosing = donode;
				match(Tag.DO);
				s1 = stmt();
				match(Tag.WHILE);
				match('(');
				expr = bool();
				match(')');
				match(';');
				donode.init(s1, expr);
				Stmt.Enclosing = savedStmt;
				return donode;
			case Tag.BREAK:
				match(Tag.BREAK);
				match(';');
				return block();
			default:
				return assign();
		}
	}
	
	// 赋值语句
	Stmt assign() throws IOException{
		Stmt stmt;
		Token tok = look;
		match(Tag.ID);
		Id id = top.get(tok);
		if (id == null){
			error(tok.toString() + " undeclared");
		}
		if (look.tag == '='){
			move();
			stmt = new Set(id, bool());
		}
		else {
			Access a = offset(id);
			match('=');
			stmt = new SetElem(a, bool());
		}
		match(';');
		return stmt;
	}
	
	Expr bool() throws IOException{
		Expr expr = join();
		while (look.tag == Tag.OR){
			Token tok = look;
			move();
			expr = new Or(tok, expr, join());
		}
		return expr;
	}
	
	Expr join() throws IOException{
		Expr expr = equality();
		while (look.tag == Tag.AND){
			Token tok = look;
			move();
			expr = new And(tok, expr, equality());
		}
		return expr;
	}
	
	Expr equality() throws IOException{
		Expr x = rel();
		while (look.tag == Tag.EQ || look.tag == Tag.NE){
			Token tok = look;
			move();
			expr = new Rel(tok, expr, rel());
		}
		return expr;
	}
	
	Expr rel() throws IOException{
		Expr expr = expr();
		switch (look.tag){
			case '<':
			case Tag.LE:
			case Tag.GE：
			case '>':
				Token tok = look;
				move();
				return new Rel(tok, expr, expr());
			default:
				return expr;
		}
	}
	
	Expr expr() throws IOException{
		Expr expr = term();
		while (look.tag == '+' || look.tag == '-'){
			Token tok = look;
			move();
			expr = new Arith(tok, expr, term());
		}
		return expr;
	}
	
	Expr term() throws IOException{
		Expr expr = unary();
		while (look.tag == '*' || look.tag == '/'){
			Token tok = look;
			move();
			expr = new Arith(tok, expr, unary());
		}
		return expr;
	}
	
	Expr unary() throws IOException{
		if (look.tag == '-'){
			move();
			return new Unary(Word.minus, unary());
		}
		else if (look.tag == '!'){
			Token tok = look;
			move();
			return new Not(tok, unary());
		}
		else {
			return factor();
		}
	}
	
	Expr factor() throws IOException{
		Expr expr = null;
		switch (look.tag){
			case '(':
				move();
				expr = bool();
				match(')');
				return expr;
			case Tag.NUM:
				expr = new Constant(look, Type.Int);
				move();
				return expr;
			case Tag.REAL:
				expr = new Constant(look, Type.Float);
				move();
				return expr;
			case Tag.TRUE:
				expr = Constant.True;
				move();
				return expr;
			case Tag.FALSE:
				expr = Constant.False;
				move();
				return expr;
			case Tag.ID:
				String s = look.toString();
				Id id = top.get(look);
				if (id == null){
					error(look.toString() + " undeclared");
				}
				move();
				if (look.tag != '['){
					return id;
				}
				else {
					return offset(id);
				}
			default:
				error("syntax error");
				return expr;
		}
	}
	
	Access offset(Id id) throws IOException{
		Expr expr;
		Expr w;
		Expr e1, e2;
		Expr loc;
		Type type = expr.type;
		match('[');
		expr = bool();
		match(']');
		type = ((Array)type).of;
		w = new Constant(type.width);
		e1 = new Arith(new Token('*'), expr, w);
		loc = e1;
		while (look.tag == '['){
			match('[');
			expr = bool();
			match(']');
			type = ((Array)type).of;
			w = new Constant(type.width);
			e1 = new Arith(new Token('*'), expr, w);
			e2 = new Arith(new Token('+'), loc, e1);
			loc = e2;
		}
		return new Access(id, loc, type);
	}
}
