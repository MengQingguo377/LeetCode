#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int sum = 0;
    void PreOrdered(TreeNode* root)
    {
        if(root)
        {
            if(root->left)
            {
                if(!root->left->left && !root->left->right)
                    sum += root->left->val;
            }
            PreOrdered(root->left);
            PreOrdered(root->right);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        PreOrdered(root);
        return sum;
    }
};

class Solution1 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root)
        {
            if(root->left && !root->left->left && !root->left->right)
                return root->left->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
            else 
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
        else return 0;
    }
};

int main()
{
    return 0;
}