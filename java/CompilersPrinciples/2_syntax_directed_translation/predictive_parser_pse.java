/**
	预测分析器伪代码
*/
void stmt(){
	switch (lookhead){
		case expr:
			match(expr);
			match(';');
			break;
		case "if":
			match("if");
			match('(');
			match(expr);
			match(')');
			stmt();
			break;
		case "for":
			match("for");
			match("(");
			optexpr();
			match(';');
			optexpr();
			match(';');
			optexpr();
			match(')');
			stmt();
			break;
		case other:
			match(other);
			break;
		default:
			report("syntax error");
			
	}
}

void optexpr(){
	if (lookhead == expr){
		match(expr);
	}
}

void match(terminal t){
	if (lookhead == t){
		lookhead = nextTerminal;
	}
	else{
		report("syntax error");
	}
}