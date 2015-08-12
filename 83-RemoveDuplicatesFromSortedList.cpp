/*=============================================================================
#     FileName: 83-RemoveDuplicatesFromSortedList.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-12 07:50:34
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
        ListNode* deleteDuplicates(ListNode* head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode *tail = head;
            while (tail) {
                while (tail->next && tail->val == tail->next->val) {
                    tail->next = tail->next->next;
                }
                tail = tail->next;
            }
            return head;
        }
};
