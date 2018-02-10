/**
	closure 计算
	伪代码
*/
setOfItems closure(I){
	J = I;
	repeat
		for (A-->(alpha).B(beta) in J){
			for (B-->(gma) in G){
				if (item(B-->.(gma)) is not in J){
					J.add(B-->.(gma));
				}
			}
		}
	until no new item add into J 
	return J;
}