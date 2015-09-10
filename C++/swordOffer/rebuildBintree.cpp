/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if (pre.size() < 1)
            {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[0]);
        int index = binsearch(in, pre[0]);
        
        vector<int> l_in;
        vector<int> l_pre;
        for (int i = 0; i < index; i++)
            {
            l_in.push_back(in[i]);
            l_pre.push_back(pre[i + 1]);
        }
        vector<int> r_in;
        vector<int> r_pre;
        for (int j = index + 1; j < in.size(); j++)
            {
            r_in.push_back(in[j]);
            r_pre.push_back(pre[j]);
        }
        
        root->left = reConstructBinaryTree(l_pre, l_in);
        root->right = reConstructBinaryTree(r_pre, r_in);
        return root;
    }
    
	// 二分查找有问题，无法通过测试！
    int binsearch(vector<int> vec, int key)
        {
        int hi = vec.size();
        int lo = 0;
        while (lo < hi)
            {
            int mid = (lo + hi) >> 1;
            if (vec[mid] > key)
                {
                hi = mid;
            }
            else
                {
                lo = mid + 1;
            }
        }
        return lo - 1;
    }
};

// 通过测试
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if (pre.size() < 1)
            {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[0]);
        int index = 0;
        while (pre[0] != in[index])	// in[index++]，有问题！相等后，继续加1了！
            {
            index++;
        }
         
        vector<int> l_in;
        vector<int> l_pre;
        for (int i = 0; i < index; i++)
            {
            l_in.push_back(in[i]);
            l_pre.push_back(pre[i + 1]);
        }
        vector<int> r_in;
        vector<int> r_pre;
        for (int j = index + 1; j < in.size(); j++)
            {
            r_in.push_back(in[j]);
            r_pre.push_back(pre[j]);
        }
         
        root->left = reConstructBinaryTree(l_pre, l_in);
        root->right = reConstructBinaryTree(r_pre, r_in);
        return root;
    }
};
