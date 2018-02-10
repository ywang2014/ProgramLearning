/**
	非终结符expr、rest、term的伪代码
*/
void expr(){
	trem();
	rest();
}

void rest(){
	if (lookhead == '+'){
		match('+');
		term();
		print('+');
		rest();
	}
	else if (lookhead == '-'){
		match('-');
		term();
		print('-');
		rest();
	}
	else{
		// 不做任何处理
	}
}

void term(){
	if (isDigit(lookhead)){
		t = lookhead;
		match(lookhead);
		print(t);
	}
	else{
		report("syntax error");
	}
}

/*************************************************/
// 消除尾递归
void rest(){
	while (true){
		if (lookhead == '+'){
			match('+');
			term();
			print('+');
			continue;
		}
		else if (lookhead == '-'){
			match('-');
			term();
			print('-');
			continue;
		}
		else{
			break;
		}
	}
}