/**
	the science of programming
	
	咖啡罐问题
		给你一个盛装了一些黑豆和白豆的咖啡罐，以及一堆额外的黑豆。
		重复如下操作，直到罐中只有一粒豆子
			随机从罐中选择两粒豆子，如果颜色相同，则扔掉它们，并且罐中放入一粒黑豆；
			如果颜色不同，则将白豆返回罐中。
	分析：
		每次操作豆子总数减 1，说明豆子肯定会取到剩下一粒。
		2白：放一粒黑豆，白豆减2，黑豆加1，总数减1;
		2黑：放一粒黑豆，黑豆减1;
		1白1黑：返回白豆，黑豆减1.
*/

create a bool array, false represent black beans, true represent white beans;
create two random number(range between 0 and size of array), represent the index of array.
update the array.
	if the same beans, remove, and push a black beans.
	else push back the white beans.
	
loop until remain one bean.