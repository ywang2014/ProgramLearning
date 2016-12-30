/**
	lvalue()伪代码
*/
Expr lvalue(x : Expr){
	if (isIdNode(x)){
		return x;
	}
	else if (isAccessNode(x) && isIdNode(y)){
		return new Access(y, rvalue(z));
	}
	else{
		reprot("error");
	}
}