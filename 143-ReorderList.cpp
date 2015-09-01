/*=============================================================================
#     FileName: 143-ReorderList.cpp
#         Desc: AC, 68ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-09-01 07:55:16
#      Version: 0.0.1
#   LastChange: 2015-09-01 07:55:16
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
        ListNode *reverseList(ListNode *head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode *prev = NULL, *cur = head, *next = head->next;
            while (next) {
                cur->next = prev;
                prev = cur;
                cur = next;
                next = next->next;
            }
            cur->next = prev;
            return cur;
        }
        void reorderList(ListNode* head) {
            if (!head || !head->next) {
                return ;
            }
            ListNode *fast = head, *slow = head, *tmp = NULL;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            tmp = slow;
            slow = slow->next;
            tmp->next = NULL;
            slow = reverseList(slow);
            fast = head;
            while (slow) {
                tmp = fast->next;
                fast->next = slow;
                slow = slow->next;
                fast->next->next = tmp;
                fast = tmp;
            }
        }
};

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution solution;
    solution.reorderList(node1);
    while (node1) {
        cout << node1->val << " ";
        node1 = node1->next;
    }

}
