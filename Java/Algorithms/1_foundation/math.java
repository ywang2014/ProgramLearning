/**
	静态方法：sqrt
*/
public static double sqrt(double c){
	if (c < 0){
		return Double.NaN;
	}
	double err = 1e-15;
	double t = c;
	while (Math.abs(t - c / t) > err){
		t = (t + c / t) / 2.0;
	}
	
	return t;
}

// 计算绝对值的方法
public static int abs(int n){
	return n < 0 ? -n : n;
}

public static double abs(double x){
	return x < 0.0 ? -x : x;
}

public static boolean isPrime(int n){
	int half = (int)sqrt(n);
	for (int i = 2; i <= half; i++){
		if (n % i == 0){
			return false;
		}
	}
	
	return true;
}

public static double harmonic(int n){
	double sum = 0.0;
	for (int i = 1; i <= n; i++){
		sum += 1.0 / i;
	}
	
	return sum;
}
