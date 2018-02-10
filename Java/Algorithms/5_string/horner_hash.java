/**
	Horner方法，除留余数法计算散列值
*/
private long hash(String key, int M){
	long h = 0;
	for (int j = 0; j < M; j++){
		h = (R * h + key.charAt(j)) % Q;
	}
	return h;
}