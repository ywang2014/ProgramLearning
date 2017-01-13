/**
	LR语法分析程序
	移入-归约
*/
a = first_alphbet(w$);
while (1){
	s = stack.top();
	if (action[s, a] == moveinto(t)){
		stack.push(t);
		a = next(w);
	}
	else if (action[s, a] == reduced(A-->beta)){
		l = len(beta);
		while (l--){
			stack.pop();	// 弹出|beta|个字符
		}
		t = stack.top();
		stack.push(goto(t, A));
		print(A-->beta)
	}
	else if (action[s, a] == accepted){
		break;
	}
	else{
		error_solution();
	}
}