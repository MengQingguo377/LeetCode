#include<iostream>
#include<queue>
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
    TreeNode* min_feasible(TreeNode* root, int low, int high)
    {
        if(!root->right)
            return nullptr;
        else
        {
            if(root->right->val > high)
                return max_feasible(root->right, low, high);
            else if(root->right->val >= low)
                return root->right;
            else return min_feasible(root->right, low, high);
        }
    }
    TreeNode* max_feasible(TreeNode* root, int low, int high)
    {
        if(!root->left)
            return nullptr;
        else
        {
            if(root->left->val < low)
                return min_feasible(root->left, low, high);
            else if(root->left->val <= high)
                return root->left;
            else return max_feasible(root->left, low, high);
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        queue<TreeNode*>que;
        if(root->val < low) root = min_feasible(root, low, high);
        if(root->val > high) root = max_feasible(root, low, high);
        if(root == nullptr) return nullptr;
        que.push(root);
        while(!que.empty())
        {
            if(que.front()->left != nullptr)
            {
                if(que.front()->left->val < low)
                    que.front()->left = min_feasible(que.front()->left, low, high);
                if(que.front()->left != nullptr) 
                    que.push(que.front()->left);
            }
            if(que.front()->right != nullptr)
            {
                if(que.front()->right->val > high)
                    que.front()->right = max_feasible(que.front()->right, low, high);
                if(que.front()->right != nullptr)
                    que.push(que.front()->right);
            }
            que.pop();
        }
        return root;
    }
};

int main()
{
    return 0;
}