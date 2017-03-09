/**
	逆向数据流问题的迭代算法
*/
IN[EXIT] = Vexit;
for (除EXIT外的每个基本块B){
	IN[B] = T;
}
while (isChanged(IN)){
	for (除EXIT外的每个基本块B){
		// Interaction 交互运算符
		OUT[B] = Interaction(IN[S]);	// s是B的一个后继
		IN[B] = f(OUT[B]);	// f传递函数
	}
}