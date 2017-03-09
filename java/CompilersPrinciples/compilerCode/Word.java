/**
	Word
	
	管理保留字、标识符、复合词法单元(&&)
	管理中间代码中运算符的书写形式(- minus)
*/
package lexer;

public class Word extends Token{
	public String lexeme = "";
	
	public Word(String s, int tag){
		super(tag);
		lexeme = s;
	}
	
	public String toString(){
		return lexeme;
	}
	
	public static final Word 
		and = new Word("&&", Tag.AND),
		or = new Word("||", Tag.OR),
		eq = new Word("==", Tag.EQ),
		ne = new Word("!=", Tag.NE),
		le = new Word("<=", Tag.LE),
		ge = new Word(">=", Tag.GE),
		minus = new Word("minus", Tag.MINUS),
		True = new Word("true", Tag.TRUE),
		False = new Word("false", Tag.FALSE),
		temp = new Word("t", Tag.TEMP);
}