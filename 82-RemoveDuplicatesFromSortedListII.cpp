/*=============================================================================
#     FileName: 82-RemoveDuplicatesFromSortedListII.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-10 17:42:58
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
            ListNode *nHead = NULL, *tail = NULL;
            while (head && head->next) {
                if (head->val != head->next->val) {
                    if (!tail) {
                        nHead = head;
                        tail = head;
                    } else {
                        tail->next = head;
                        tail = tail->next;
                    }
                    head = head->next;
                } else {
                    while (head->next && head->val == head->next->val) {
                        head = head->next;
                    }
                    head = head->next;
                }
            }
            if (tail) {
                tail->next = head;
            } else {
                nHead = head;
            }
            return nHead;
        }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(1), *node3 = new ListNode(2);
    //ListNode *node1 = new ListNode(1), *node2 = new ListNode(1), *node3 = new ListNode(1), *node4 = new ListNode(3), *node5 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
/*    node3->next = node4;*/
    /*node4->next = node5;*/

    Solution solution;
    node1 = solution.deleteDuplicates(node1);
    while (node1) {
        cout << node1->val << " ";
        node1 = node1->next;
    }
    cout << endl;
}
