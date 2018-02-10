/**
	ArrayList 动态数组，自动调整数组的大小
	典型实现，在需要的时候，capacity *= 2
*/
public ArrayList<String> merge(String[] words, String[] more){
	ArrayList<String> sentence = new ArrayList<String>();
	for (String w : words){
		sentence.add(w);
	}
	for (String m : more){
		sentence.add(m);
	}
	
	return sentence;
}