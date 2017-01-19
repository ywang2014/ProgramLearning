/**
	合一算法
*/
boolean unify(Node n, Node m){
	s = find(n);
	t = find(m);
	if (s == t){
		return true;
	}
	else if (s and t are the same base type){
		return true;
	}
	else if (s == Node(s1, s2, op) && t == Node(t1, t2, op)){
		union(s, t);
		return unify(s1, t1) && unify(s2, t2);
	}
	else if (s is varible || t is varible){
		union(s ,t);
		return true;
	}
	else {
		return false;
	}
}