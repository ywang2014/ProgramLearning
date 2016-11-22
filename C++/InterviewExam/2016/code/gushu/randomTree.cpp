/**
	创建一棵树
	
	
	节点包含：
		一个整数，随机生成；
		一块内存，随机生成；
		孩子节点个数，随机生成
	树的深度，也是一个随机数

	随机函数：random()
*/
struct Node{
	int elem;	// 节点元素值
	char *mem;	// 内存区域
	int num;	// 孩子节点数目
	struct **childs; // 孩子节点数组，使用数组，方便创建树时，使用递归操作，容易找到节点。
	
	Node(){
		elem = random();
		mem = new char[random()];
		num = random();
		childs = new Node*[num]; 
	}
};

class RandomTree{
	Node *root;
	int depth;
	
public:
	RandomTree(){
		depth = random();
		createTree(root, depth);
	}
	
private:
	void createTree(Node *root, int depth){
		root = new Node();
		if (depth != 1){
			for (int i = 0; i < root->num; i++){
				createTree(root->childs[i], depth-1);
			}
		}
	}
}
