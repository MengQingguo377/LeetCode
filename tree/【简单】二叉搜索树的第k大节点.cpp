#include<iostream>
#include<queue>
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
    void afterOrder(TreeNode* root, priority_queue<int, vector<int>, greater<int> > &pq, int k)
    {
        if(root)
        {
            afterOrder(root->right, pq, k);
            if(pq.size() == k)
            {
                if(pq.top() < root->val)
                {
                    pq.pop();
                    pq.push(root->val);
                }
            }
            else pq.push(root->val);
            afterOrder(root->left, pq, k);
        }
    }
    int kthLargest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int> >pq;
        afterOrder(root, pq, k);
        return pq.top();
    }
};

class Solution1 {  
public:
    void afterOrder(TreeNode* root, int &ans, int &i, int k)
    {
        if(root)
        {
            afterOrder(root->right, ans, i, k);
            if(i == k) return;
            ans = root->val;
            i++;
            afterOrder(root->left, ans, i, k);
        }
    }
    int kthLargest(TreeNode* root, int k) {
        int i = 0, ans;
        afterOrder(root, ans, i, k);
        return ans;
    }
};

int main()
{
    return 0;
}