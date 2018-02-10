/**
	模拟NFA
*/
s = epsilon-closure(s0);
c = nextChar();
while (c != eof){
	s = epsilon-closure(move(s, c));
	c = nextChar();
}
if (S && F != null){
	return "yes";
}
else{
	return "no";
}

// 加入一个不在newStates中的新状态
addState(s){
	nesStates.push(s); // 将s压入栈newStates中
	alreadyOn[s] = TRUE;
	for (t on move[s, t]){
		if (!alreadyOn[t]){
			addState(t);
		}
	}
}

for (s in oldStates){
	for (t in move[s, c]){
		if (!alreadyOn[t]){
			addState(t);
		}
	}
	将s弹出oldStates栈;
}

for (s in newStates){
	将s弹出栈newStates;
	oldStates.push(s);
	alreadyOn[s] = FALSE;
}