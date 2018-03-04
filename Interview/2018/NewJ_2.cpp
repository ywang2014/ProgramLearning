/**
	算法题：
*/

// atoi()
int atoi(const char *str){
    if (str == nullptr || *str == '\0'){
        error(); // invalid
    }
    bool isNegative = false;
    if (*str == '+'){
        str++;
    }
    if (*str == '-'){
        str++;
        isNegative = true;
    }
    if (!isDigit(*str)){
        error();
    }
    int number = 0;
    while (*str != '\0'){
        if (isDigit(*str)){
            number = number * 10 + charToInt(*str);
            str++;
        } else {
            error();
        }
    }
    return isNegative ? 0 - number : number;
}

bool isDigit(const char ch){
    return ch >= '0' && ch <= '9';
}

int charToInt(const char ch){
    return ch - '0';
}



// 一个数组[-1,3,6,-9,2,-5,-1,9,3,-3]， 正负值都有,求这个数组里最大的连续子段和

// 6 -1 -3 
int getMaxSubarray(int *arr, int n){
    if (arr == nullptr || n < 0){
        error();    // invalid parameters
    }
     
    int maxSum = 0;
    int currentSum = 0;
     
    int startIndex = 0;
    int currentStartI = 0;
     
    int endIndex = 0;
    int currentEndI = 0;
     
    for (int i = 0; i < n; i++){
        currentSum += arr[i];
        currentEndI++;
        if (maxSum < currentSum){
            maxSum = currentSum;
            startIndex = currentStartI;
            endIndex = currentEndI;
        }
        if (currentSum < 0){
            currentSum = 0;
            currentStartI = i+1;
            currentEndI = i;    // ?
        }
    }   
    printf("start index = %d, end index = %d\n", startIndex, endIndex);
    return maxSum;
}

