#include<iostream>
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
    vector<int> arr, cnt;
    int front_e, count;
    void MinOrdered(TreeNode* root)
    {
        if(root)
        {
            MinOrdered(root->left);
            if(arr.empty())
            {
                arr.push_back(root->val);
                cnt.push_back(1);
                front_e = root->val;
                count = 1;
            }
            else
            {
                if(root->val == front_e)
                    count++;
                else
                {
                    front_e = root->val;
                    count = 1;
                }
                if(count == cnt.back())
                {
                    arr.push_back(root->val);
                    cnt.push_back(count);
                }
                else if(count > cnt.back())
                {
                    arr.clear();
                    cnt.clear();
                    arr.push_back(root->val);
                    cnt.push_back(count);
                }
            }
            MinOrdered(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        MinOrdered(root);
        return arr;
    }
};

int main()
{
    return 0;
}