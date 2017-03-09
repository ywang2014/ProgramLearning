/**
	计算到达定值的迭代算法
*/
OUT[ENTRY] = null;
for (除ENTRY之外的每个基本块B){
	OUT[B] = null;
}
while (isChanged(OUT[B])){
	for (除ENTRY之外的每个基本块B){
		IN[B] = Up OUT[P];	// p是B的一个前驱
		OUT[B] = genB U (IN[B] - killB)
	}
}