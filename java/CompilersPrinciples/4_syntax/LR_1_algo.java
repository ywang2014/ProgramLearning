/**
	LR(1)项集族的算法
*/
setOfItems closure(I){
	repeat
		for ([A-->alpha.Bbeta, a] in I){
			for (B-->gma in G1){
				for (b in first(betaa)){
					I.add([B-->.gma, b]);
				}
			}
		}
	until I is unchanged
	return I;
}

setOfItems goto(I, X){
	J.initial();
	for ([A-->alpha.Xbeta, a] in I){
		J.add([A-->alpha.Xbeta, a]);
	}
	return closure(J);
}

void items(G1){
	C = {closure}({[S1-->.S, $]});
	repeat
		for (I in C){
			for (X in Xs){
				if (goto(I, X) is not empty and not in C){
					c.add(goto(I, X));
				}
			}
		}
	until C is unchanged
}