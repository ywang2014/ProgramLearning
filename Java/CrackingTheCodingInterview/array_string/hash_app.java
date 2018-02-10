/**
	散列表
*/
public HashMap<Integer, Student> buildMap(Student[] students){
	HashMap<Integer, Student> map = new HashMap<Integer, Student>();
	for (Student s : students){
		map.put(s.getId(), s);
	}
	
	return map;
}
// 现成的数据结构，直接使用即可