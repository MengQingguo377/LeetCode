/*
看题目描述看不懂，还是看评论区才看懂题目：
题目的意思是子节点需要用()来包裹。举例来说，二叉树[root,left,right]，则转换为root(left)(right)。如果只有left为空节点，则输出root()(right)；如果只有right为空节点则可以忽略右节点的()，输出为root(left)。
*/

#include<iostream>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void tree_to_str(TreeNode* t, string& s)
    {
        if(t) s += to_string(t->val);
        if(!t || (!t->left && !t->right)) return;
        if(t->left)
        {
            s += "(";
            tree_to_str(t->left, s);
            s += ")";
        }
        if(!t->left) s += "()";
        if(t->right)
        {
            s += "(";
            tree_to_str(t->right, s);
            s += ")";
        }
    }
    string tree2str(TreeNode* t) {
        string s = "";
        tree_to_str(t, s);
        return s;
    }
};

int main()
{
	return 0;
}
