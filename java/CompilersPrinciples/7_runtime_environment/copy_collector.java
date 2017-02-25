/**
	拷贝垃圾回收器
*/
void copyingCollector(){
	for (From空间中的所有对象o){
		newLocation(o) = null;
	}
	unscanned = free = To空间的开始地址;
	for (r 根集中的每个引用){
		r = lookupNewLocation(r);
	}
	while (unscanned != free){
		o = unscanned所指位置上的对象;
		for (r o对象中的每个引用){
			o.r = lookupNewLocation(o.r);
		}
		unscanned = unscanned + sizeof(o);
	}
}
	
// 如果一个对象被移动过了，查找这个对象的新位置
// 否则将对象设置为待扫描状态
lookupNewLocation(o){
	if (newLocation(o) == null){
		newLocation(o) = free;
		free = free + sizeof(O);
		将对象o拷贝到newLocation(o);
	}
	return newLocation(o);
}