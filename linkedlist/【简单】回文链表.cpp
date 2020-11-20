#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int N = 0;
        vector<ListNode*>ls;
        while(head)
        {
            ls.push_back(head);
            head = head->next;
            N++;
        }
        int left = 0, right = N-1;
        while(left < right)
        {
            if(ls[left++]->val != ls[right--]->val)
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}