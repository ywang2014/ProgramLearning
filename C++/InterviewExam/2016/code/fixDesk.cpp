/**
	修理桌子
	Arthur最近搬到了新的别墅，别墅特别大，原先的桌子显得比较小，所以他决定换一张新的桌子。他买了一张特别大的桌子，
	桌子是由很多条桌腿进行支撑的，可是回到家之后他发现桌子不稳，原来是桌子腿长度不太相同。他想要自己把桌子修理好，
	所以他决定移除掉一些桌腿来让桌子变得平稳。桌子腿总共有n条腿，第i条腿长度为li，Arthur移除第i桌腿要花费代价为di。
	假设k条腿桌子平稳的条件:超过一半桌腿能够达到桌腿长度的最大值。例如：一条腿的桌子是平稳的，两条腿的桌子腿一样长
	时是平稳的。请你帮Arthur计算一下是桌子变平稳的最小总代价。 
	
	输入:
		第一行数据是一个整数：n (1≤n≤105)，n表示桌腿总数。
		第二行数据是n个整数：l1, l2, ..., ln (1≤li≤105)，表示每条桌腿的长度。
		第三行数据是n个整数：d1, d2, ..., dn (1≤di≤200)，表示移除每条桌腿的代价。
	输出:
		输出让桌子变平稳的最小总代价
		
	输入：
		6
		2 2 1 1 3 3
		4 3 5 5 2 1
	输出：
	8
*/

struct legNode{
	int length;
	int price;
	
	void set(int len, int pri){
		length = len;
		price = pri;
	}
};

int cmp_len(legNode a, legNode b){
	return a.length - b.length;
}

int cmp_pri(legNode a, legNode b){
	return a.price - b.price;
}

int getMinPrice(int *len, int *price, int n){
	int count[106] = { 0 };	// 1 <= li <= 105
	legNode *legs_len = new legNode[n];
	legNode *legs_pri = new legNode[n];
	
	for (int i = 0; i < n; i++){
		legs_len[i].set(len[i], price[i]);
		legs_pri[i].set(len[i], price[i]);
		count[len[i]]++;
	}
	
	sort(legs_len, legs_len + n, cmp_len);
	sort(legs_pri, legs_pri + n, cmp_pri);
	
	int legnums = n;
	int l_index = n - 1;
	int p_index = 0;
	int maxLen = legs_len[l_index].length;
	int res = 0;
	
	while (count[maxLen] < legnums / 2){
		// 这种处理方法，没有考虑数量问题，只是考虑单个代价最小
		//res += count[legs_pri[p_index].length] * legs_pri[p_index].price;	// 不行，长度相同，代价不一定相同
		// legnums -= count[legs_pri[p_index].length];
		// count[legs_pri[p_index].length] = 0;
		res += legs_pri[p_index].price;
		legnums--;
		count[legs_pri[p_index].length]--;
		p_index++;
		
		int k = 0;
		for (int k = l_index; k >= 0; k--){
			if (count[k] != 0){
				break;
			}
		}
		l_index = k;
		maxLen = legs_len[l_index].length;
	}
	delete [] legs_len;
	delete [] legs_pri;
	
	return res;
}


int main(){
	int n = 0;
	while (cin >> n){
		int *len = new int[n];
		int *price = new int [n];
		for (int i = 0; i < n; i++){
			cin >> len[i];
		}
		for (int i = 0; i < n; i++){
			cin >> price[i];
		}
		
		cout << getMinPrice(len, price, n) << endl;
		delete[] len;
		delete[] price;
	}
	
	return 0;
}


/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>

using namespace std;

struct legNode{
	int length;
	int price;
	
	void set(int len, int pri){
		length = len;
		price = pri;
	}
};

int cmp_len(legNode a, legNode b){
	return a.length - b.length;
}

int cmp_pri(legNode a, legNode b){
	return a.price - b.price;
}

int getMinPrice(int *len, int *price, int n){
	int count[120] = { 0 };	// 1 <= li <= 105
	legNode *legs_len = new legNode[n];
	legNode *legs_pri = new legNode[n];
	
	for (int i = 0; i < n; i++){
		legs_len[i].set(len[i], price[i]);
		legs_pri[i].set(len[i], price[i]);
		count[len[i]]++;
	}
	
	sort(legs_len, legs_len + n, cmp_len);
	sort(legs_pri, legs_pri + n, cmp_pri);
	
	int legnums = n;
	int l_index = n - 1;
	int p_index = 0;
	int maxLen = legs_len[l_index].length;
	int res = 0;
	
	while (count[maxLen] < legnums / 2){
		// 这种处理方法，没有考虑数量问题，只是考虑单个代价最小
		//res += count[legs_pri[p_index].length] * legs_pri[p_index].price;	// 不行，长度相同，代价不一定相同
		// legnums -= count[legs_pri[p_index].length];
		// count[legs_pri[p_index].length] = 0;
		res += legs_pri[p_index].price;
		legnums--;
		count[legs_pri[p_index].length]--;
		p_index++;
		
		int k = 0;
		for (int k = l_index; k >= 0; k--){
			if (count[k] != 0){
				break;
			}
		}
		l_index = k;
		if (l_index < 0){
            break;
        }
		maxLen = legs_len[l_index].length;
	}
	
	delete [] legs_len;
	delete [] legs_pri;
	
	return res;
}

int main(){
	int n = 0;
	while (cin >> n){
		int *len = new int[n];
		int *price = new int [n];
		for (int i = 0; i < n; i++){
			cin >> len[i];
		}
		for (int i = 0; i < n; i++){
			cin >> price[i];
		}
		
		cout << getMinPrice(len, price, n) << endl;
	}
	
	return 0;
}

///// 发生段错误

/************ 参考答案 ******/
大体思路是把先把输入的腿长映射到一个106维的腿长数目数组，数组中的值为对应腿长的的数目。然后从后往前遍历
没碰到一个腿长，将比他高的腿长砍掉，同时计算还需要砍多少桌腿，对剩余的桌腿排序砍掉对应部分，然后计算最小值。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int >l,d,d_cut;
        int a[106]={0};
        int li,di;
        for(int i=0;i<n;i++)
        {
            cin>>li;
            l.push_back(li);
            a[li]++;
        }
        int minCost=0;
        for(int i=0;i<n;i++)
        {
            cin>>di;
            d.push_back(di);
            minCost+=di;
        }
        for(int i=105;i>0;i--)
        {
            int cost=0;
            d_cut.clear();
            if(a[i])
            {
                int cutLegNum=l.size()-a[i];
                for(int j=i+1;j<=105;j++)
                {
                    cutLegNum-=a[j];
                }
                cutLegNum-=(a[i]-1);
                for(int k=0;k<n;k++)
                {
                    if(l[k]<i)
                        d_cut.push_back(d[k]);
                    if(l[k]>i)
                        cost+=d[k];
                }
                if(cutLegNum>0)
                {
                    sort(d_cut.begin(),d_cut.end());
            for (int k = 0; k <cutLegNum; k++)
                        cost+=d_cut[k];
                    if(cost<minCost)
                        minCost=cost;
                }     
            }
        }
        cout<<minCost<<endl;
    }
    return 0; 
}