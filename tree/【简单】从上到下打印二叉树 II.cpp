#include<iostream>
#include<vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> >res;
        vector<int>arr;
        queue<TreeNode>que, q;
        que.push(*root); // res.push_back({root->val});
        while(!que.empty())
        {
            arr.clear();
            while(!que.empty())
            {
                arr.push_back(que.front().val);
                q.push(que.front());
                que.pop();
            }
            res.push_back(arr);
            while(!q.empty())
            {
                if(q.front().left) que.push(*q.front().left); 
                if(q.front().right) que.push(*q.front().right);
                q.pop();
            }
        }
        return res;
    }
};

class Solution_youhua {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> >res;
        vector<int>arr;
        queue<TreeNode>que;
        int rec_lay_n = 1, next_lay_n = 0;
        que.push(*root); // res.push_back({root->val});
        while(!que.empty())
        {
            arr.clear();
            while(rec_lay_n--)
            {
                arr.push_back(que.front().val);
                if(que.front().left) {que.push(*que.front().left); next_lay_n++;} 
                if(que.front().right) {que.push(*que.front().right); next_lay_n++;}
                que.pop();
            }
            res.push_back(arr);
            rec_lay_n = next_lay_n;
            next_lay_n = 0;
            // while(!q.empty())
            // {
            //     if(q.front().left) que.push(*q.front().left); 
            //     if(q.front().right) que.push(*q.front().right);
            //     q.pop();
            // }
        }
        return res;
    }
};

int main()
{
    return 0;
}