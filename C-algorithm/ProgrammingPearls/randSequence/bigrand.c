/**
	bigrand 30位
	
	rand() 随机返回15个随机位
*/

int bigrand(){
	return RAND_MAX * rand() + rand();
}

int randint(int lo, int hi){
	return lo + bigrand() % (hi - lo + 1);
}