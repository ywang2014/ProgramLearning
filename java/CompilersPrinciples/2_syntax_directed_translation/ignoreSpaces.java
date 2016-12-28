/**
	跳过空白部分
*/
for (; ; peek = nextInputCharacter()){
	if (isBlank(peek)){
		continue;
	}
	else if (isNewLine(peek)){
		line++;
	}
	else{
		break;
	}
}