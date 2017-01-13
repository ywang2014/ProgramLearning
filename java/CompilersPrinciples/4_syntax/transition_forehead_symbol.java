/**
	发现传播和自发生成的向前看符号
*/
// K is LR(0)的项集I的内核
for (A-->alpha>beta in K){
	J = closure({[A-->alpha.beta, #]});
	if ([B-->gma.Xdelta, a] in J and a != #){
		断定goto(I, X)中的项B-->gmaX.delta的向前看符号a是自发生成的;
	}
	if ([B-->gma.Xdelta, a] in J){
		断定向前看符号从I中的项A-->alpha.beta传播到了goto(I, X)中的项B-->gmaX.delta之上;
	}
}