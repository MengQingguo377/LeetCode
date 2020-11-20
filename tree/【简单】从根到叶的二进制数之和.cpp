#include<iostream>
#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        queue<TreeNode*>q;
        queue<int>subsum;
        int sum = 0;
        q.push(root); subsum.push(root->val);
        while (!q.empty())
        {
            TreeNode* node = q.front(); int num = subsum.front();
            q.pop(); subsum.pop();
            if(!node->left && !node->right)
            {
                sum = (sum + num) % int(1e9+7);
            }
            if(node->left)
            {
                q.push(node->left);
                subsum.push(num<<1 + node->left->val);
            }
            if(node->right)
            {
                q.push(node->right);
                subsum.push(num<<1 + node->right->val);
            }
        }
        
    }
};

int main()
{
    return 0;
}