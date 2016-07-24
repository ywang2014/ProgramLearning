/**
	The course of Software Design and Development Practice is objectionable. ZLC is facing a serious problem .
	There are many points in K-dimensional space .Given a point. ZLC need to find out the closest m points. Euclidean distance is 
	used as the distance metric between two points. The Euclidean distance between points p and q is the length of the line segment 
	connecting them.In Cartesian coordinates, if p = (p 1, p 2,..., p n) and q = (q 1, q 2,..., q n) are two points in Euclidean n-space, 
	then the distance from p to q, or from q to p is given by: 
		欧氏距离
		
	input：
		In the first line of the text file .there are two non-negative integers n and K. They denote respectively: the number of points, 
		1 <= n <= 50000, and the number of Dimensions,1 <= K <= 5. In each of the following n lines there is written k integers, representing 
		the coordinates of a point. This followed by a line with one positive integer t, representing the number of queries,1 <= t <=10000.
		each query contains two lines. The k integers in the first line represent the given point. In the second line, there is one integer m, 
		the number of closest points you should find,1 <= m <=10. The absolute value of all the coordinates will not be more than 10000.
		There are multiple test cases. Process to end of file.
	output：
		For each query, output m+1 lines:
			The first line saying :”the closest m points are:” where m is the number of the points.
			The following m lines representing m points ,in accordance with the order from near to far
		It is guaranteed that the answer can only be formed in one ways. The distances from the given point to all the nearest m+1 points are 
		different. That means input like this:
		
	Sample input：
		3 2
		1 1
		1 3
		3 4
		2
		2 3
		2
		2 3
		1
	Sample output：
		the closest 2 points are:
		1 3
		3 4
		the closest 1 points are:
		1 3
*/

#include <iostream>
#include <math.h>

using namespace std;


struct Node{
    int *point;
	int k;
    double d;
	
	Node(){
		Node(5);
	}
	
	Node(int n){
		k = n;
		point = new int[k];
		for (int i = 0; i < k; i++){
			point[i] = 0;
		}
		d = 0.0;
	}
	
	~Node(){
		delete[] point;
	}
};

void assignNode(Node &node, const int *point, const double dis){
	for (int i = 0; i < node.k; i++){
		node.point[i] = point[i];
	}
	node.d = dis;
}

void exch(Node a, Node b){
	for (int i = 0; i < a.k; i++){
		int tmp = a.point[i];
		a.point[i] = b.point[i];
		b.point[i] = tmp;
	}
	double dis = a.d;
	a.d = b.d;
	b.d = dis;
}


double calculateDistance(int *p1, int *p2, int k){
	double res = 0.0;
	for (int i = 0; i < k; i++){
		res += (p1[i] - p2[i]) * (p1[i] - p2[i]);
	}
	return sqrt(res);
}

void findClosestMpoints(int **matrix, int *fir, int n, int k, int m){
    // 创建一个m元素的优先队列
    // Node *res = new Node(k)[m+1];
	Node *res = new Node[m+1];
	for (int i = 0; i < n; i++){
		double dis = calculateDistance(fir, matrix[i], k);
		
		int j = (i < m ? i : m);
		// 插入排序
		for (; j > 0 && dis < res[j-1].d; j--){
			exch(res[j], res[j-1]);
		}
		assignNode(res[j], matrix[i], dis);
	}
	
	cout << "the closest " << m << " points are:" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < k; j++){
			cout << res[i].point[j] << " ";
		}
		cout << endl;
	}
}


int main(){
    int n;
    int k;
    while(cin >> n){
        cin >> k;
        int **points = new int*[n];
        for (int i = 0; i < n; i++){
            points[i] = new int[k];
            for (int j = 0; j < k; j++){
                cin >> points[i][j];
            }
        }
        int t = 0;
        cin >> t;
        int *first = new int[k];
        for (int i = 0; i < t; i++){
            for (int j = 0; j < k; j++){
                cin >> first[j];
            }
            int m = 0;
            cin >> m;
            // TODO
            findClosestMpoints(points, first, n, k, m);
        }
    }
	
	return 0;
}