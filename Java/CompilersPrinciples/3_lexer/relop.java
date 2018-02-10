/**
	relop的状态转换图的实现概述
*/
TOKEN getRelop(){
	TOKEN retToken = new(RELOP);
	while (true){
		// repeat character processing until a return or failure occurs
		switch (state){
			case 0:
				c = nextChar();
				if (c == '<'){
					state = 1;
				}
				else if (c == '='){
					state = 5;
				}
				else if (c == '>'){
					state = 6;
				}
				else{
					fail(); // lexeme is not a relop
				}
				break;
				
			case 1:
				c = nextChar();
				if (c == '='){
					state = 2;
				}
				else if (c == '>'){
					state = 3;
				}
				else{
					state = 4; // other
				}
				break;
				
			case 2:
				retToken.attribute = LE;
				return retToken;
				
			case 3:
				retToken.attribute = NE;
				return retToken;
				
			case 4:
				retract();
				retToken.attribute = LT;
				return retToken;
			
			case 5:
				retToken.attribute = EQ;
				return retToken;
				
			case 6:
				c = nextChar();
				if (c == '='){
					state = 7;
				}
				else{
					state = 8; // other
				}
				break;
			
			case 7:
				retToken.attribute = GE;
				return retToken;
			
			case 8:
				retract();	// 后退一个输入字符到输入流中
				retToken.attribute = GT;
				return retToken;
		}
	}
}