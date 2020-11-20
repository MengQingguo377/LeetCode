#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void reverseTree(TreeNode* root)
    {
        if(!root) return;
        if(root->left || root->right) // 不是叶子节点
        {
            reverseTree(root->left);
            reverseTree(root->right);
            swap(root->left, root->right);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        reverseTree(root);
        return root;
    }
};

int main()
{
    return 0;
}