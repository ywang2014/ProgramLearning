/**
	Baker 标记-清扫式垃圾回收算法
*/
void garbageCollection(){
	List scanned = new List();
	Queue unscanned = new Queue();
	// 将跟集中引用对象都添加到unscanned中，同时将这些对象从unreached中删除
	while (! unscanned.isEmpty()){
		Object ob = unscanned.dequeue();
		scanned.append(ob);
		for (o in 对象ob中所引用的对象){
			if (o is in unreached){
				unreached.erase(o);
				unscanned.emqueue(o);
			}
		}
	}
	Free = Free + unreached;
	unreached = scanned;
}