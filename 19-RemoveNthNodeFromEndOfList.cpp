/*=============================================================================
#     FileName: 19-RemoveNthNodeFromEndOfList.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 20:37:42
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (!head->next) {
                return NULL;
            }
            map<int, ListNode*> nodeMap;
            int index = 1;
            while (head) {
                nodeMap.insert(pair<int, ListNode*>(index, head));
                head = head->next;
                index ++;
            }
            index --;
            if (n == 1) {
                nodeMap[index - 1]->next = NULL;
                return nodeMap[1];
            }
            if (n == index) {
                nodeMap[1]->next = NULL;
                return nodeMap[2];
            }
            nodeMap[index - n]->next = nodeMap[index - n + 2];
            nodeMap[index - n + 1]->next = NULL;
            return nodeMap[1];
        }
};
