/**
	rvalue()伪代码
*/
Expr rvalue(x : Expr){
	if (isIdOrConstantNode(x)){
		return x;
	}
	else if (isOpOrRelNode(x)){
		t = newTempNode;
		t = rvalue(y) op rvalue(z);
		return t;
	}
	else if (isAccessNode(x)){
		t = newTempNode;
		t = lvalue(x);
		return t;
	}
	else if (isAssignNode(x)){
		z = rvalue(z);
		lvalue(y) = z;
		return z;
	}
}