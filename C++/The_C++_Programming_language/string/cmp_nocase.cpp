/**
	cmp_nocase
	不区分大小写的比较函数
*/

int cmp_nocase(const string &s, const string &s2){
	string::const_iterator p1 = s.begin();
	string::const_iterator p2 = s2.begin();
	
	while (p1 != s.end() && p2 != s2.end()){
		if (toupper(*p1) == toupper(*p2)){
			++p1;
			++p2;
		}
		else{
			return toupper(*p1) < toupper(*p2) ? -1 : 1;
		}
	}
	
	return (s.size() == s2.size()) ? 0 : (s.size() < s2.size() ? -1 : 1);
}