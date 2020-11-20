/*
 * @Description: LeetCode刷题记录
 * @Author: 孟庆国
 * @LastEditTime: 2020-11-08 11:52:10
 * @LastEditors: 孟庆国
 */
#include<bits/stdc++.h>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>stk;
        TreeNode* node = root;
        while(!stk.empty() || node)
        {
            if(node)
            {
                stk.push(node);
                node = node->left;
            }
            else
            {
                node = stk.top(); stk.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}