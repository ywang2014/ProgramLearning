/**
	子集构造法
*/
一开始，epsilon-closure(s0)是Dstates中的唯一状态，且它未加标记;
while (在Dstates中有一个未标记状态T){
	marked(T);
	for (每个输入符号a){
		U = epsilon-closure(move(T, a));
		if (U不在Dstates中){
			将U加入到Dstates中，且不加标记;
		}
		Dtran[T, a] = U;
	}
}

// 计算epsilon-closure(T)
将T的所有状态压入stack中;
将epsilon-closure(T)初始化为T;
while (!stack.isEmpty()){
	t = stack.pop();
	for (每个满足如下条件的u: 从t出发有一个标号为epsilon的转换到达状态u){
		if (u不在epsilon-closure(T)中){
			将u加入到epsilon-closure(T)中;
			将u压入栈中;
		}
	}
}