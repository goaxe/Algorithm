/*=============================================================================
#     FileName: 138-CopyListWithRandomPointer.cpp
#         Desc: AC, 124ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-08-31 20:59:15
#      Version: 0.0.1
#   LastChange: 2015-08-31 20:59:15
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <leetcode.h>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if (!head) {
                return NULL;
            }
            unordered_map<RandomListNode *, RandomListNode *> nodeMap;
            RandomListNode *tmp = head;
            while (tmp) {
                nodeMap.insert(pair<RandomListNode *, RandomListNode *>(tmp, new RandomListNode(tmp->label)));
                tmp = tmp->next;
            }
            tmp = head;
            while (tmp) {
                RandomListNode *copy = nodeMap[tmp];
                copy->next = nodeMap[copy->next];
                copy->random = nodeMap[copy->random];
                tmp = tmp->next;
                copy = copy->next;
            }
            return nodeMap[head];
        }
};
