/*=============================================================================
#     FileName: 92-ReverseLinkedListII.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-18 22:48:29
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
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if (!head || !head->next) {
                return head;
            }
            ListNode *rHead = NULL, *rTail = NULL, *tmp = NULL;
            tmp = head;
            if (m == 1) {
                rHead = head;
            } else {
                for (int i = 0; i < m - 2; i ++) {
                    tmp = tmp->next;
                }
                rHead = tmp->next;
                tmp->next = NULL;
            }
            rTail = rHead;
            for (int i = 0; i < n - m; i ++) {
                rTail = rTail->next;
            }
            tmp = rTail->next;
            rTail->next = NULL;
            rHead = reverseList(rHead);
            rTail = rHead;
            while (rTail->next) {
                rTail = rTail->next;
            }
            rTail->next = tmp;
            if (m == 1) {
                return rHead;
            }
            tmp = head;
            while (tmp->next) {
                tmp = tmp->next;
            }
            tmp->next = rHead;
            return head;
        }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3), *node4 = new ListNode(4), *node5 = new ListNode(5);
    node1->next= node2;
    node2->next= node3;
    node3->next= node4;
    node4->next= node5;
    Solution solution;
    ListNode *head = solution.reverseBetween(node1, 2, 4);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
