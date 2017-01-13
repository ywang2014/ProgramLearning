/**
	规范LR(0)项集族的计算
*/
void items(G1){
	C = { closure({S1-->S}) };
	repeat
		for (I in C){
			for (X in 文法符号){
				if (goto(I, X) is not empty and not in C){
					C.add(goto(I, X));
				}
			}
		}
	until C is unchanged
}