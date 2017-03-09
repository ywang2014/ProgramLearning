/**
	计算可用表达式的迭代算法
*/
OUT[ENTRY] = null;
for (除ENTRY之外的每个基本块B){
	OUT[B] = U;
}
while (isChanged(OUT)){
	for (除ENTRY之外的每个基本块B){
		IN[B] = intersection(OUT[P]);	// p是B的一个前驱
		OUT[B] = e_genB U (IN[B] - e_killB);
	}
}