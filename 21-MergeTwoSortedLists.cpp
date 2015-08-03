/*=============================================================================
#     FileName: 21-MergeTwoSortedLists.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 22:34:10
#      History:
=============================================================================*/

#include <leetcode.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (!l1 || !l2) {
                return l1 ? l1 : l2;
            }
            ListNode *head = NULL, *tail = NULL;
            while (l1 && l2) {
                ListNode *node = new ListNode(min(l1->val, l2->val));
                if (!head) {
                    head = node;
                    tail = head;
                } else {
                    tail->next = node;
                    tail = tail->next;
                }
                if (l1->val <= l2->val) {
                    l1 = l1->next;
                } else {
                    l2 = l2->next;
                }
            }
            if (!l1) {
                l1 = l2;
            }
            while (l1) {
                tail->next = new ListNode(l1->val);
                tail = tail->next;
                l1 = l1->next;
            }
            return head;
        }
};
