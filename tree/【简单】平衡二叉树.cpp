#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution { // 自顶向下 时间复杂度O(n^2)
public:
    int height(TreeNode* root)
    {
        return !root ? 0 : max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return abs(height(root->left)-height(root->right))<=1 &&
               isBalanced(root->left) && 
               isBalanced(root->right); 
    }
};

class Solution1 { // 自底向上 时间复杂度O(n)
public:
    int dept(TreeNode* node)
    {
        if(!node) return 0;
        int left = dept(node->left), right = dept(node->right);
        if(left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        else return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return dept(root) != -1;
    }
};

int main()
{
    return 0;
}