/*=============================================================================
#     FileName: 25-ReverseNodesInK-Group.cpp
#         Desc: AC, 25ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-03 20:06:02
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
            ListNode *prev = NULL, *current = head, *next = head->next;
            while (next) {
                current->next = prev;
                prev = current;
                current = next;
                next = next->next;
            }
            current->next = prev;
            return current;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (!head || !head->next || k == 1) {
                return head;
            }
            ListNode *start = head, *end = NULL, *nHead = NULL, *nTail = NULL;
            while (true) {
                end = start;
                for (int i = 1; i < k; i ++) {
                    if (end && end->next) {
                        end = end->next;
                    } else {
                        if (!nTail) {
                            return head;
                        }
                        nTail->next = start;
                        return nHead;
                    }
                }
                ListNode *tmp = end->next;
                end->next = NULL;
                if (nHead == NULL) {
                    nHead = reverseList(start);
                    nTail = nHead;
                } else {
                    nTail->next = reverseList(start);
                }
                start = tmp;
                while (nTail->next) {
                    nTail = nTail->next;
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
    ListNode *head = solution.reverseKGroup(node1, 3);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
