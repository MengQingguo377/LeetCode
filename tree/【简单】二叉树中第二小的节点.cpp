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

class Solution {
public:
    int min1 = -1, min2 = -1;
    void afterordered(TreeNode* root)
    {
        if(root)
        {
            afterordered(root->left);
            afterordered(root->right);
            if(!root->left)
            {
                if(min1 == -1) min1 = root->val;
                else if(root->val < min1)
                {
                    min2 = min1;
                    min1 = root->val;
                }
                else if((min2 == -1 || root->val < min2) && root->val != min1)
                    min2 = root->val;
            }
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        afterordered(root);
        return min2;
    }
};

int main()
{
    return 0;
}