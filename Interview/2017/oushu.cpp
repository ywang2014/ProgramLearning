/**
	偶数面试第二轮
*/

1.第三题
3,2,2,3,1
// 木桶最大的装水能力。

2.第二题
A=[4, 8, 20, 30, 100]
[0,4), [4, 8),...[100,MAX)
n ->5
find(A, n)->4
n->90
find(A, n)->30
n->1000
find(A,n)->100

int find(int *arr, int n, int k){
    if (arr == nullptr || n < 1){
        return -1;
    }
	return binarySearch(arr, 0, n, k);
}

int binarySearch(int *arr, int low, int high){
    while (low < high){
		int mid = (high - low) / 2 + low;
		if (arr[mid] > k){
			high = mid;
		} else {
			low = mid + 1;
		}
	}  
	return arr[low-1];
}
        

// 判断一个字符串是否是合法的整数：
// 1.有符号 +、-
// 2.2^16范围内 short

bool isInvalidInt(char *str){
    if (str == nullptr || *str != '\0'){
        return false;    // invalid parameter
    }
    bool isNegative = false;
    if (*str == '+')
    {
        str++;
    } else if (*str == '-'){
        isNegative = true;
        str++;
    }
    if (! isDigit(*str)){
        return false;
    }
    
    int number = 0;
    while (*str != '\0'){
        if (isDigit(*str)){
            number = number * 10 + getIntNumber(*str);
            if (checkNumberRange(number, isNegative)){
                return false;
            }
        } else {
            return false;
        }
        str++;
    }
    return true;
}

bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
}

getIntNumber(char ch);

#define MAX_NUMBER = 1 << 16;

bool checkNumberRange(int number, bool isNegative){
    return !((isNegative && number > MAX_NUMBER) || (!isNegative && number >= MAX_NUMBER));
}



