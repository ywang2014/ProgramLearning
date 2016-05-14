/**
	根据离散概率随机返回int值
	A[i]表示出现i的概率
		A[i]中个元素之和为1
*/

public static int discrete(double[] a){
	double r = StdRandom.random();
	double sum = 0.0;
	for (int i = 0; i < a.length; i++){
		sum += a[i];
		if (sum >= r){
			return i;
		}
	}
	return -1;
}