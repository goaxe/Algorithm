/*=============================================================================
#     FileName: 100-SameTree.cpp
#         Desc: 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 07:16:20
#      History:
=============================================================================*/

#include <leetcode.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (!p && !q) {
                return true;
            }
            if ((p && !q) || (!p && q)) {
                return false;
            }
            if (p->val != q->val) {
                return false;
            }
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
};
