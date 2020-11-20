#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int find_max_index(const vector<int>& nums, int l, int r)
    {
        int max_ind = l;
        for(int i = l+1; i <= r; i++)
            max_ind = (nums[i] > nums[max_ind]) ? i : max_ind;
        return max_ind;
    }
    TreeNode* build_max_binary_tree(const vector<int>& nums, int l, int r)
    {
        if(l > r) return nullptr;
        int max_ind = find_max_index(nums, l, r);
        TreeNode* root = new TreeNode(nums[max_ind]);
        root->left = build_max_binary_tree(nums, l, max_ind-1);
        root->right = build_max_binary_tree(nums, max_ind+1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build_max_binary_tree(nums, 0, nums.size()-1);
    }
};

int main()
{
    return 0;
}