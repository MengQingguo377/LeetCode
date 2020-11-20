#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        stack<Node>s;
        Node node;
        vector<int>arr;
        vector<Node*>childNode;
        s.push(*root);
        while(!s.empty())
        {
            node = s.top(); s.pop();
            arr.push_back(node.val);
            childNode = node.children;
            if(childNode.empty()) continue;
            for(vector<Node*>::iterator it = --childNode.end();;)
            {
                s.push(*(*it));
                if(it == childNode.begin()) break;
                it--;
            }
        }
        return arr;
    }
};

int main()
{
    return 0;
}