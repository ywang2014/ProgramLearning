/**
	widen函数的伪代码
	仅考虑integer和float两种类型
*/
Addr widen(Addr a, Type t, Type w){
	if (t == w){
		return a;
	}
	else if (t == integer && w = float){
		temp = new Temp();
		gen(temp '=' '(float)' a);
		return temp;
	}
	else error;
}