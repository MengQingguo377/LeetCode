#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return nullptr;
        if(head->val == val) return head->next;
        ListNode *p=nullptr, *q=head, *r=head->next;
        while(q->val != val && r)
        {
            p = q;
            q = r;
            r = r->next;
        }
        if(q->val == val)
            p->next = r;
        return head;
    }
};

int main()
{
    return 0;
}