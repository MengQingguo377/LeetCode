#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return true; // 空树 或者 只有根节点
        if(!root->left || !root->right) return false; // 该数根节点下还有子树，所以如果左右有一个为空则不对称
        stack<TreeNode*>leftnodes, rightnodes;
        leftnodes.push(root->left); rightnodes.push(root->right);
        while(!leftnodes.empty() && !rightnodes.empty())
        {
            TreeNode *leftp = leftnodes.top(), *rightp = rightnodes.top();
            leftnodes.pop(); rightnodes.pop();
            if(leftp->val != rightp->val) return false;
            if((leftp->left && !rightp->right) ||  // leftp左节点不为空 rightp右节点为空
               (!leftp->left && rightp->right) ||  // leftp左节点为空 rightp右节点不为空
               (leftp->right && !rightp->left) ||  // leftp右节点不为空 rightp左节点为空
               (!leftp->right && rightp->left))    // leftp右节点为空 rightp左节点不为空
               return false;
            if(leftp->left) leftnodes.push(leftp->left);
            if(leftp->right) leftnodes.push(leftp->right);
            if(rightp->right) rightnodes.push(rightp->right);
            if(rightp->left) rightnodes.push(rightp->left);
        }
        return true;
    }
};

int main()
{
    return 0;
}