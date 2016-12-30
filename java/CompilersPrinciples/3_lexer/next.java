/**
	字符串匹配失效函数 -- next()
*/
t = 0;
f(1) = 0;
for (int s = 1; s < n; s++){
	while (t > 0 && b[s+1] != b[t+1]){
		t = f(t);
	}
	if (b[s+1] == b[t+1]){
		t++;
		f(s+1) = t;
	}
	else{
		f(s+1) = 0;
	}
}