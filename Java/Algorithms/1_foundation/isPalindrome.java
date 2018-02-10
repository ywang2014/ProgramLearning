/**
	判断字符串是否是回文
*/
public static boolean isPalindrome(String s){
	int N = s.length();
	for (int i = 0; i < N / 2; i++){
		if (s.charAt(i) != s.charAt(N - 1 - i)){
			return false;
		}
	}
	return true;
}

// 从文件名中提取文件名和扩展名
String s = args[0];
int dot = s.indexOf(".");
String base = s.substring(0, dot);
String extension = s.substring(dot + 1, s.length());

// 打印标准输入中所有含有通过命令行指定的字符串的行
String query = args[0];
while (!StdIn.isEmpty()){
	String s = StdIn.readLine();
	if (s.contains(query)){
		StdOut.println(s);
	}
}

// 从输入中获取数组
String input = StdIn.readAll();
String[] words = input.split("\\s+");