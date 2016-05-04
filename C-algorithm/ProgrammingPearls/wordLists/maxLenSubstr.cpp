/**
	给定输入文本文件，查找其中最长的重复子字符串
*/

// O(n^2)
int maxLenSubstr(char *str){
	int maxlen = -1;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			int thislen = comlen(&c[i], &c[j]);
			if (thislen > maxlen){
				maxlen = thislen;
				maxi = i;
				maxj = j;
			}
		}
	}
	
	return maxlen;
}


int comlen(char *p, char *q){
	int i = 0;
	while (*p && (*p++ == *q++)){
		i++;
	}
	return i;
}