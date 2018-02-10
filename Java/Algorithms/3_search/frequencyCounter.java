/**
	符号表的用例
	
	性能测试
*/
public class FrequencyCounter{
	public static void main(String[] args){
		int minlen = Integer.parseInt(args[0]);
		ST<String, Integer> st = new ST<String, Integer>();
		while (!StdIn.isEmpty()){
			String word = StdIn.readString();
			if (word.length() < minlen){
				continue;
			}
			if (!st.contains(word)){
				st.put(word, 1);
			}
			else{
				st.put(word, st.get(word) + 1);
			}
		}
		String maxStr = " ";
		st.put(maxStr, 0);
		for (String word : st.keys()){
			if (st.get(word) > st.get(maxStr)){
				max = word;
			}
		}
		StdOut.println(maxStr + " " + st.get(maxStr));
	}
}