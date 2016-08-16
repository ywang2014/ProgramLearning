/**
    题目描述

    有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
    给定数组A及它的大小n，请返回最大差值。
    测试样例：
        [10,5],2
        返回：0
        [2676,4662,8383,357,6595],5
        返回：6238

*/

class LongestDistance {
public:
    int getDis(int* A, int n) {
        // write code here
        if (n <= 1){
            return 0;
        }
        int l = 0;
        int r = n-1;
        int min_l = A[l++];
        int max_r = A[r--];

        while (l <= r){
            if (min_l > A[l]){
                min_l = A[l];
            }
            if (max_r < A[r]){
                max_r = A[r];
            }
            l++;
            r--;
        }
        int diff = max_r - min_l;
        return diff > 0 ? diff : 0;
    }

    int getDis2(int* A, int n) {
        // write code here
        if (n < 2){
            return 0;
        }
        int min_l = A[0];
        int res = 0;
        for (int i = 1; i < n; i++){
            int diff = A[i] - min_l;
            if (res < diff){
                res = diff;
            }
            if (min_l > A[i]){
                min_l = A[i];
            }
        }
        return res;
    }
};

#include <iostream>

using namespace std;

int main(){
    int n = 0;
    while (cin >> n){
        int *arr = new int[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        LongestDistance ld;
        cout << ld.getDis(arr, n) << endl;
        cout << ld.getDis2(arr, n) << endl;
    }
}
