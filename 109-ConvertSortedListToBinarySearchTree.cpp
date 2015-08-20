/*=============================================================================
#     FileName: 109-ConvertSortedListToBinarySearchTree.cpp
#         Desc: AC, 36ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 10:13:07
#      History:
=============================================================================*/

#include <leetcode.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            if (!head) {
                return NULL;
            }
            if (!head->next) {
                return new TreeNode(head->val);
            }
            int len = 0;
            ListNode *tmp = NULL, *tail = NULL;
            tmp = head;
            while (tmp) {
                tmp = tmp->next;
                len ++;
            }
            tmp = head;
            for (int i = 0; i < len / 2 - 1; i ++) {
                tmp = tmp->next;
            }
            tail = tmp;
            tmp = tmp->next;
            tail->next = NULL;
            TreeNode *root = new TreeNode(tmp->val);
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(tmp->next);
            return root;
        }
};
