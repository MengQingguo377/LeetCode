#include<iostream>
#include<queue>
#include<vector>
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
    vector<int> depth_father(TreeNode* root, int x, int y)
    {
        vector<int>arr(4, 0);
        queue<TreeNode*>q;
        q.push(root); q.push(nullptr);
        int depth = 0;
        while(q.front() != nullptr)
        {
            depth++;
            while(q.front() != nullptr)
            {
                if(q.front()->left)
                {
                    if(q.front()->left->val == x)
                    {
                        arr[0] = q.front()->val;
                        arr[1] = depth + 1;
                    }
                    if(q.front()->left->val == y)
                    {
                        arr[2] = q.front()->val;
                        arr[3] = depth + 1;
                    }
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    if(q.front()->right->val == x)
                    {
                        arr[0] = q.front()->val;
                        arr[1] = depth + 1;
                    }
                    if(q.front()->right->val == y)
                    {
                        arr[2] = q.front()->val;
                        arr[3] = depth + 1;
                    }
                    q.push(q.front()->right);
                }
                q.pop();
            }
            q.pop(); q.push(nullptr);
        }
        return arr;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int>arr = depth_father(root, x, y);
        if(arr[1] == arr[3] && arr[0] != arr[2])
            return true;
        return false;
    }
};

int main()
{
    return 0;
}