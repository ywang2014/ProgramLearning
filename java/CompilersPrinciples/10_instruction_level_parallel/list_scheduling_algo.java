/**
	列表指令调度算法
*/
RT = an empty resource reservation list;
for (visit every node in N by a topological sort with priority){	// 按照带优先级的拓扑排序访问N中的每个节点n
	s = max(S(p) + de);	// e = p-->n in E(边集合)
	// 根据每一个指令的各个前驱在何时开始，计算这个指令最早可以何时开始
	while (exist i make that RT[s+i] + RTn[i] > R){
		s = s + 1;
		// 进一步把这个指令后延，直到所需资源变得可用为止
	}
	S(n) = s;
	for (all i){
		RT[s+i] = RT[s+i] + RTn[i];
	}
}