/**
	计算活跃变量的迭代算法
*/
IN[EXIT] = null;
for (除EXIT之外的每个基本块B){
	IN[B] = null;
}
while (isChanged(IN)){
	for (除EXIT之外的每个基本块B){
		OUT[B] = Us IN[S]; // s是B的一个后代
		IN[B] = useB U (OUT[B] - defB);
	}
}