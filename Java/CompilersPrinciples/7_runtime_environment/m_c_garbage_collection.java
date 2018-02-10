/**
	标记并压缩的垃圾回收器
	mark compact
*/
void garbage(){
	/* mark */
	Queue unscanned = new Queue(根集引用的对象的集合);
	while (unscanned is not empty){
		object ob = unscanned.dequeue();
		for (o in ob对象中引用的对象){
			if (o.reached == 0){
				o.reached = 1;
				unscanned.emqueue(o);
			}
		}
	}
	
	/* 计算新的位置 */
	free = heap.start;
	for (从低端开始，遍历堆区中的每个存储块所对应的对象ob){
		if (ob.reached == 1){
			newLocation(ob) = free;
			free = free + sizeof(ob);
		}
	}
	
	/* 重新设置引用目标，并移动已被访问的对象 */
	for (从低端开始，堆区中的每个存储块所对应的对象ob){
		if (ob.reached == 1){
			for (r in ob中的每个引用){
				ob.r = newLocation(ob.r);
			}
			// 将ob拷贝到NewLocation(ob)处
		}
	}
	for (r in 根集中的每个引用){
		r = newLocation(r);
	}
}