#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        queue<TreeNode*> q;
        queue<int> path;
        q.push(root);
        path.push(root->val);
        while(!q.empty())
        {
            TreeNode* node = q.front(); q.pop();
            int path_sum = path.front(); path.pop();
            if(!node->left && !node->right && path_sum==sum) // node是叶子节点且此时路径长度等于sum
                return true;
            if(node->left) // 左节点不为空
            {
                q.push(node->left);
                path.push(path_sum + node->left->val);
            }
            if(node->right)
            {
                q.push(node->right);
                path.push(path_sum + node->right->val);
            }
        }
        return false;
    }
};

class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) return sum==root->val;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

int main()
{
    return 0;
}