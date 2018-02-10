/**
	给定一颗二叉树，其中每个节点都含有一个数值。设计一个算法，打印节点数值总和等于某个给定值的所有路径。
	注意：路径不一定非得从二叉树根节点开始，或者叶节点结束。
*/

void findSum(TreeNode head, int sum, ArrayList<Integer> buffer, int level){
	if (head == null){
		return ;
	}
	int tmp = sum;
	buffer.add(head.data);
	for (int i = level; i > -1; i--){
		tmp -= buffer.get(i);
		if (tmp == 0){
			print(buffer, i, level);
		}
	}
	ArrayList<Integer> c1 = (ArrayList<Integer>) buffer.clone();
	ArrayList<Integer> c2 = (ArrayList<Integer>) buffer.clone();
	findSum(head.left, sum, c1, level + 1);
	findSum(head.right, sum, c2, level + 1);
}

void print(ArrayList<Integer> buffer, int level, int i2){
	for (int i = level; i <= i2; i++){
		System.out.print(buffer.get(i) + " ");
	}
	System.out.println();
}