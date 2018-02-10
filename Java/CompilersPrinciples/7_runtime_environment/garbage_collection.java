/**
	标记-清扫式垃圾回收
*/
void garbageCollection(){
	/* 标记阶段 */
	// 所有的对象的可达性标记为0，reached=0
	Queue unscanned = new Queue();
	// 把被根集引用的对象的reached位设置为1，并把它们加入到unscanned列表中
	while (!unscanned.isEmpty()){
		Object ob = unscanned.dequeue();
		for (object 是ob中所引用的对象){
			if (object.reached == 0){	// 还未扫描到的对象
				object.reached = 1;
				unscanned.enqueue(object);
			}
		}
	}
	/* 清扫阶段 */
	List Free = new List();
	for (堆区中的每一个对象o){
		if (o.reached == 0){	// 不可达的对象
			Free.append(o);		// 回收内存
		}
		else{
			o.reached = 0;		// 下一次垃圾回收做准备
		}
	}
}
