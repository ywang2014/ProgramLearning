"""
	将n展开为2的指数幂，如下：
	1 = 2(0)
	2 = 2
	3 = 2+1 = 2+2(0)
	7 = 4+2+1 = 2(2)+2+2(0)
	
"""

def get_arr_2(n):
    res = []
    while n > 0:
        if n % 2 != 0:
            res.append(1)
        else:
            res.append(0)
        n = int(n / 2)
    return res


def get_string_rec(l2):
    n = len(l2) - 1
    res = ""
    flag = True
    while n >= 0:
        if l2[n] != 0:
            s = ""
            if flag:
                if n == 1:
                    s = "2"
                else:
                    s = "2(" + solution(n) + ")"
                flag = False
            else:
                if n == 1:
                    s = "2"
                else:
                    s = "+2(" + solution(n) + ")"
            res += s
        n -= 1
    return res


def solution(n):
    if n == 2 or n == 0:
        return str(n)
    return get_string_rec(get_arr_2(n))


if __name__ == "__main__":
    # print(int(9/2))
    # for i in range(10):
    #     print(i)
    #     print(get_arr_2(i))

    # print(get_string(get_arr_2(8))) # 2(3)
    # print(get_string(get_arr_2(3))) # 2(1)+2(0)

    print(solution(8))  # 2(2+2(0))
    print(solution(3))