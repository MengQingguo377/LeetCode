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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*>que;
        que.push(p); que.push(q);
        TreeNode *pp, *qq;
        while(!que.empty())
        {
            pp = que.front(); que.pop();
            qq = que.front(); que.pop();
            if((pp->left && !qq->left)   || 
               (pp->right && !qq->right) ||
               (!pp->left && qq->left)   || 
               (!pp->right && qq->right) ||
               (pp->val != qq->val))
               return false;
            if(pp->left) { que.push(pp->left); que.push(qq->left); }
            if(pp->right) { que.push(pp->right); que.push(qq->right); }            
        }
        return true;
    }
};

int main()
{
    return 0;
}