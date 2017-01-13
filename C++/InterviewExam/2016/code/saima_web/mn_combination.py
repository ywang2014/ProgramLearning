"""
赛马网笔试题目：
	计算mn的排列组合
		C(4, 2) = 6
		C(10, 2) = 45
"""

def solution(n, m):
    arr = [0] * n
    for i in range(m):
        arr[i] = 1
    end = False
    count = 1
    while not end:
        end = True
        for i in range(n-1):
            if arr[i] == 1 and arr[i+1] == 0:
                count += 1
                arr[i], arr[i+1] = 0, 1
                end = False
                left_shift(arr, i)
                break
    return count


def left_shift(arr, n):
    count = 0
    for i in range(n):
        if arr[i] == 1:
            count += 1
    for i in range(n):
        if i < count:
            arr[i] = 1
        else:
            arr[i] = 0

if __name__ == "__main__":
    print(solution(10, 2))