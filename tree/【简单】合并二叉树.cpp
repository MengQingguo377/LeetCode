#include<iostream>
#include<stack>
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        TreeNode *node1, *node2;
        queue<TreeNode*>q;
        q.push(t1); q.push(t2);
        while (!q.empty())
        {
            node1 = q.front(); q.pop();
            node2 = q.front(); q.pop();
            node1->val += node2->val; // 将两节点值相加
            if(node1->left && node2->left) // 两节点都有左子树，则将两者的左子树都加入队列
            {
                q.push(node1->left); q.push(node2->left);
            }
            if(!node1->left && node2->left) // t1的左节点不存在，t2的左节点存在
                node1->left = node2->left;
            if(node1->right && node2->right) // 两节点都有右子树，则将两者的右子树都加入队列
            {
                q.push(node1->right); q.push(node2->right);
            }
            if(!node1->right && node2->right) // t1的右节点不存在，t2的右节点存在
                node1->right = node2->right;
        }
        return t1;
    }
};

int main()
{
    return 0;
}