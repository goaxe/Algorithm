/*=============================================================================
#     FileName: 24-SwapNodesInPairs.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-03 19:41:31
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
        ListNode* swapPairs(ListNode* head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode *prev = NULL, *first = head, *second = head->next, *nHead = second;
            while (true) {
                first->next = second->next;
                second->next = first;
                if (first != head) {
                    prev->next = second;
                }
                prev = first;
                if (first->next && first->next->next) {
                    second = first->next->next;
                    first = first->next;
                } else {
                    return nHead;
                }
            }
            return nHead;
        }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3), *node4 = new ListNode(4), *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution solution;
    ListNode *head = solution.swapPairs(node1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
