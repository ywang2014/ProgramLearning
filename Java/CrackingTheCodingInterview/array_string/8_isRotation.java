/**
	假定一个方法isSubstring，可检查一个单词是否为其他字符串的子串。
	给定两个字符串s1,s2,请编写代码检查s2是否是s1旋转而成的，要求只能调用一次isSubtring。
*/
public boolean isRotation(String s1, String s2){
	int len = s1.length();
	if (len == s2.length() && len > 0){
		String s1s1 = s1 + s1;
		return isSubstring(s1s1, s2);
	}
	
	return false;
}