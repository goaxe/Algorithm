/*=============================================================================
#     FileName: 116-PopulatingNextRightPointersInEachNode.cpp
#         Desc: AC, 32ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 19:57:59
#      History:
=============================================================================*/

#include <leetcode.h>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
    public:
        void connect(TreeLinkNode *left, TreeLinkNode *right) {
            if (!left || !right) {
                return ;
            }
            left->next = right;
            connect(left->left, left->right);
            connect(left->right, right->left);
            connect(right->left, right->right);
            right->next = NULL;
        }
        void connect(TreeLinkNode *root) {
            if (!root) {
                return ;
            }
            root->next = NULL;
            connect(root->left, root->right);
        }
};
