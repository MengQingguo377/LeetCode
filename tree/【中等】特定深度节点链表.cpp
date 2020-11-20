#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*>ans;
        queue<TreeNode*>q;
        TreeNode* node;
        ListNode *head, *pnode;
        q.push(tree); q.push(nullptr);
        while(q.front() != nullptr)
        {
            pnode = new ListNode(0);
            head = pnode;
            while (q.front() != nullptr)
            {
                node = q.front(); q.pop();
                pnode->next = new ListNode(node->val);
                pnode = pnode->next;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            q.pop(); q.push(nullptr);
            ans.push_back(head->next);
        }
        return ans;
    }
};

int main()
{
    return 0;
}