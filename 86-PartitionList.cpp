/*=============================================================================
#     FileName: 86-PartitionList.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-13 10:48:19
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
        ListNode* partition(ListNode* head, int x) {
            if (!head || !head->next) {
                return head;
            }
            ListNode *lHead = NULL, *lTail = NULL, *rHead = NULL, *rTail = NULL, *tmp = head;
            while (tmp) {
                if (tmp->val >= x) {
                    if (!rHead) {
                        rHead = tmp;
                        rTail = tmp;
                    } else {
                        rTail->next = tmp;
                        rTail = rTail->next;
                    }
                    tmp = tmp->next;
                    rTail->next = NULL;
                } else if (tmp->val < x) {
                    if (!lHead) {
                        lHead = tmp;
                        lTail = tmp;
                    } else {
                        lTail->next = tmp;
                        lTail = lTail->next;
                    }
                    tmp = tmp->next;
                    lTail->next = NULL;
                }
            }
            if (lTail) {
                lTail->next = rHead;
                return lHead;
            }
            return rHead;
        }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(4), *node3 = new ListNode(3), *node4 = new ListNode(2), *node5 = new ListNode(5), *node6 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    Solution solution;
    ListNode *head = solution.partition(node1, 3);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
