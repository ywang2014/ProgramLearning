/**
	基于区域的全局调度算法
*/
for (按照拓扑排序访问各个区域R，使得内层区域先于外层区域被访问){
	计算数据依赖关系;
	for (按照带优先级的拓扑排序访问R中的每个基本块B){
		CandBlocks = ControlEquiv(B) U DominatedSucc(ControlEquiv(B));
		CandInsts = CandBlocks中已可以被调度的指令;
		for (t = 0,1,2... 直到B中的所有指令都已经调度完毕){
			for (按照优先顺序访问CandInsts中的每个指令n){
				if (n在时刻t上没有资源冲突){
					S(n) = <B, t>;
					更新已分配资源信息;
					更新数据依赖关系;
				})
			}
			更新CandInsts;
		}
	}
}