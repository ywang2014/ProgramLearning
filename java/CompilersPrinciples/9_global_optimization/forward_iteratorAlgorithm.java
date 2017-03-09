/**
	前向数据流问题的迭代算法
*/
OUT[ENTRY] = Ventry;
for (除ENTRY外的每个基本块B){
	OUT[B] = T;
}
while (isChanged(OUT)){
	for (除ENTRY外的每个基本块B){
		// Interaction 交互运算符
		IN[B] = Interaction(OUT[P]);	// p是B的一个前驱
		OUT[B] = f(IN[B]);	// f传递函数
	}
}