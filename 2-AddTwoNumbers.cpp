/*=============================================================================
#     FileName: 2-AddTwoNumbers.cpp
#         Desc: AC, 40ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 17:34:28
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
        int add(int a, int b, int &c) {
            int sum = a + b + c;
            c = sum / 10;
            return sum % 10;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            if (!l1 || !l2) {
                return l1 ? l1 : l2;
            }
            ListNode *head = NULL, *tail = NULL;
            int c = 0;
            while (l1 && l2) {
                int a = l1->val, b = l2->val, sum = add(a, b, c);
                if (!head) {
                    head = new ListNode(sum);
                    tail = head;
                } else {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            if (!l1) {
                l1 = l2;
            }
            while (l1) {
                int sum = add(l1->val, 0, c);
                tail->next = new ListNode(sum);
                tail = tail->next;
                l1 = l1->next;
            }
            if (c) {
                tail->next = new ListNode(c);
                tail = tail->next;
            }
            return head;
        }
};

int main() {
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(6);
    ListNode *node6 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node4->next = node5;
    node5->next = node6;
    Solution solution;
    ListNode *head = solution.addTwoNumbers(node1, node4);
    while (head) {
        cout << head->val << "  ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
