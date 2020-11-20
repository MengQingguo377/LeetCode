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
private:   
    vector<vector<int> >arr;
public:
    void BottomLevelOrder(vector<TreeNode*> &vec)
    {
        if(!vec.empty())
        {
            vector<TreeNode*>new_vec;
            for(TreeNode* node : vec)
            {
                if(node->left) new_vec.push_back(node->left);
                if(node->right) new_vec.push_back(node->right);
            }
            BottomLevelOrder(new_vec);
            vector<int>val(vec.size());
            for(int i = 0; i < vec.size(); i++)
                val[i] = vec[i]->val;
            arr.push_back(val);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<TreeNode*>vec{root};
        BottomLevelOrder(vec);
        return arr;
    }
};

int main()
{
    return 0;
}