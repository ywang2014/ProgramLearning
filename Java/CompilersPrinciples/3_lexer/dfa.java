/**
	模拟DFA
	input: a string x end with 'eof'. the start state of DFA D is s0, the collection of end 
	states is F, the transition function is move.
*/
s = s0
c = nextChar();
while (c != eof){
	s = move(s, c);
	c = nextChar();
}
if (isInF(s)){
	return "yes";
}
else{
	return "no";
}