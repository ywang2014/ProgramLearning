/**
	汉诺塔问题
*/
public void hanoi(int n, char tower1, char tower2, char tower3){
	if (n == 0){
		return;
	}
	else if (n == 1){
		move(tower1, tower3);
		return ;
	}
	
	hanoi(n-1, tower1, tower3, tower2);	// 移动前n-1个到B
	move(tower1, tower3);	// 移动最后一个到C
	hanoi(n-1, tower2, tower1, tower3);	// 移动前n-1个到C
}

public void move(char ch1, char ch2){
	System.out.println(ch1 + " --> " + ch2);
}

// test
hanoi(10, 'A', 'B', 'C');