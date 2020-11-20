#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val > l2->val) swap(l1, l2);
        ListNode *head = l1, *p1 = l1, *p2 = l2->next;
        l1 = l1->next;
        while (l1 && l2)
        {
            if(l1->val > l2->val)
            {
                p1->next = l2;
                l2->next = l1;
                l2 = p2;
                p2 = p2 ? p2->next : nullptr;
                p1 = p1->next;
            }
            else
            {
                p1 = l1;
                l1 = l1->next;
            }            
        }
        if(!l1) p1->next = l2;
        return head;
    }
};

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    return 0;
}