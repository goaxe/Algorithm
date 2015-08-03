/*=============================================================================
#     FileName: 23-MergeKSortedLists.cpp
#         Desc: AC, 424ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-03 00:08:38
#      History:
=============================================================================*/

#include <leetcode.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator()(ListNode *node1, ListNode *node2) {
        return node1->val > node2->val;
    }
};

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode *, vector<ListNode *>, cmp> pQueue;
            ListNode *head = NULL, *tail = NULL;
            int len = lists.size();
            if (len == 0) {
                return NULL;
            }
            for (int i = 0; i < len; i ++) {
                if (!lists[i]) {
                    lists[i] = new ListNode(INT_MAX);
                } else {
                    ListNode *tmp = lists[i];
                    while (tmp->next) {
                        tmp = tmp->next;
                    }
                    tmp->next = new ListNode(INT_MAX);
                }
                pQueue.push(lists[i]);
            }
            while (pQueue.top()->val != INT_MAX) {
                ListNode *top = pQueue.top();
                ListNode *node = new ListNode(top->val);
                pQueue.pop();
                top = top->next;
                pQueue.push(top);
                if (!head) {
                    head = node;
                    tail = head;
                } else {
                    tail->next = node;
                    tail = tail->next;
                }
            }
            return head;
        }
};

int main() {
    vector<ListNode *> lists;
    for (int i = 0; i < 10; i ++) {
        lists.push_back(new ListNode(i));
    }
    Solution solution;
    ListNode *head = solution.mergeKLists(lists);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

}
