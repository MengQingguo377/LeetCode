/*
 * @Description: LeetCode刷题记录
 * @Author: 孟庆国
 * @LastEditTime: 2020-11-12 21:31:39
 * @LastEditors: 孟庆国
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        queue<int>ls_q;
        while(head != NULL)
        {
            if(ls_q.size() == k)
                ls_q.pop();
            ls_q.push(head->val);
            head = head->next;
        }
        return ls_q.front();
    }
};

class Solution { // 快慢指针
public:
    int kthToLast(ListNode* head, int k) {
        ListNode *left = head, *right = head;
        while(k--)
            right = right->next;
        while (right)
        {
            right = right->next;
            left = left->next;
        }
        return left->val;        
    }
};

int main()
{
    return 0;
}