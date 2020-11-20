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
    TreeNode* help(int low, int high, vector<int>& val)
    {
        if(low > high) return nullptr;
        int ind = low+(high-low)/2;
        TreeNode* root = new TreeNode(val[ind]);
        root->left = help(low, ind-1, val);
        root->right = help(ind+1, high, val);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(0, nums.size()-1, nums);
    }
};

int main()
{
    return 0;
}