#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode>stk;
        vector<int>arr;
        TreeNode node(0);
        int min_diff = INT_MAX;
        stk.push(*root);
        while(!stk.empty())
        {
            node = stk.top(); stk.pop();
            arr.push_back(node.val);
            if(node.left) // 左子树非空
                stk.push(*node.left);
            if(node.right) // 右子树非空
                stk.push(*node.right);
        }
        sort(arr.begin(), arr.end());
        for(int k = 1; k < arr.size(); k++)
        {
            int diff = abs(arr[k] - arr[k-1]);
            min_diff = min_diff < diff ? min_diff : diff;
        }
        return min_diff;
    }
};

class Solution1 {
private:
    int ans = INT_MAX;
    int a = -1; // 用来记录中序遍历的前一个节点值
public:
    void midOrdered(TreeNode* root)
    {
        if(root)
        {
            midOrdered(root->left);
            if(a != -1 && abs(root->val - a) < ans) 
                ans = abs(root->val - a);
            a = root->val;
            midOrdered(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        midOrdered(root);
        return ans;
    }
};

int main()
{
    return 0;
}