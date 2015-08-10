/*=============================================================================
#     FileName: 61-RotateList.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 20:33:57
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
        ListNode* rotateRight(ListNode* head, int k) {
            if (!head || !head->next) {
                return head;
            }
            int len = 0;
            ListNode *tmp = head, *nHead = NULL;
            while (tmp) {
                tmp = tmp->next;
                len ++;
            }
            k %= len;
            if (k == 0) {
                return head;
            }
            tmp = head;
            for (int i = 0; i < len - k - 1; i ++) {
                tmp = tmp->next;
            }
            nHead = tmp->next;
            tmp->next = NULL;
            tmp = nHead;
            while (tmp->next) {
                tmp = tmp->next;
            }
            tmp->next = head;
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
    ListNode *head = solution.rotateRight(node1, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
