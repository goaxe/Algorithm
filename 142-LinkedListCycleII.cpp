/*=============================================================================
#     FileName: 142-LinkedListCycleII.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-09-01 07:40:00
#      Version: 0.0.1
#   LastChange: 2015-09-01 07:40:00
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <leetcode.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if (!head || !head->next) {
                return NULL;
            }
            ListNode *fast = head, *slow = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    fast = head;
                    while (fast != slow) {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return fast;
                }
            }
            return NULL;
        }
};
