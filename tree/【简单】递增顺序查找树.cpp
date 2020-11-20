#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void midOrder(TreeNode* root, vector<int> &arr) // 中序遍历
    {
        if(root)
        {
            midOrder(root->left, arr);
            arr.push_back(root->val);
            midOrder(root->right, arr);
        }
        else return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root; 
        vector<int>arr;
        midOrder(root, arr);
        TreeNode* p = root = new TreeNode(arr[0]);
        for(int i = 1; i < arr.size(); i++)
        {
            p = p->right = new TreeNode(arr[i]);
            // p = p->right;
        }
        return root;
    }
};

int main()
{
    return 0;
}