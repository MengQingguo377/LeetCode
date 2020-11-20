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

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(root) q.push(root);
        q.push(nullptr);
        int h = 0;
        while (q.front() != nullptr)
        {
            h++;
            while(q.front() != nullptr)
            {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            q.pop(); q.push(nullptr);
        }
        return h;
    }
};

int main()
{
    return 0;
}