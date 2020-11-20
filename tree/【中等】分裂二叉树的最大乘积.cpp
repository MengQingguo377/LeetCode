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
    void treesum(TreeNode* root, vector<long> &arr)
    {
        if(root)
        {
            treesum(root->left, arr);
            treesum(root->right, arr);
            if(root->left) root->val += root->left->val;
            if(root->right) root->val += root->right->val;
            arr.push_back(long(root->val));
        }
    }
    int maxProduct(TreeNode* root) {
        vector<long>arr;
        treesum(root, arr);
        long maxans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            maxans = max((arr[i] * (arr.back() - arr[i])), maxans);
        }
        return int(maxans % long(1e9+7));
    }
};