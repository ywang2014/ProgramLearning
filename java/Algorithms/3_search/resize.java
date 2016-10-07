/**
	调整线性探测散列表的大小
*/
private void resize(int cap){
	LinearProbingHashST<Key, Value> t;
	t = new LinearProbingHashST<Key, Value>(cap);
	for (int i = 0; i < M; i++){
		if (keys[i] != null){
			t.put(keys[i], vals[i]);
		}
	}
	keys = t.keys;
	vals = t.vals;
	M = t.M;
}


private void resize(int cap){
	Key[] newKeys = new Key[cap];
	Value[] newVals = new Value[cap];
	for (int i = 0; i < M; i++){
		Key k = keys[i];
		if (k != null){
			int i = hash(k);
			while (newKeys[i] != null){
				i = (i + 1) % cap;
			}
			newKeys[i] = k;
			newVals[i] = vals[i];
		}
	}
	keys = newKeys;
	vals = newVals;
	M = cap;
}