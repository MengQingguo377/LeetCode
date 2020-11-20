/*
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
*/

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
    bool isIdentical(TreeNode* t1, TreeNode* t2) // 判断两树是否相同
    {
        queue<TreeNode*>q;
        q.push(t1); q.push(t2);
        TreeNode *node1, *node2;
        while(!q.empty())
        {
            node1 = q.front(); q.pop();
            node2 = q.front(); q.pop();
            if(node1->val != node2->val ||
               node1->left && !node2->left ||
               node1->right && !node2->right ||
               !node1->left && node2->left ||
               !node1->right && node2->right) 
               return false;
            if(node1->left)
            {
                q.push(node1->left);
                q.push(node2->left);
            }
            if(node1->right)
            {
                q.push(node1->right);
                q.push(node2->right);
            }
        }
        return true;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*>q;
        q.push(s);
        TreeNode* node;
        while(!q.empty())
        {
            node = q.front(); q.pop();
            if(node->val == t->val && isIdentical(node, t))
                return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
    }
};

class Solution1 {
public:
    bool isIdentical(TreeNode* t1, TreeNode* t2)
    {
        if(t1 && t2) 
            return t1->val == t2->val && isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right);
        else if(!t1 && !t2) return true;
        else return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t) return false;
        return isIdentical(s, t) || isIdentical(s->left, t) || isIdentical(s->right, t) ||
               isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

int main()
{
    return 0;
}
