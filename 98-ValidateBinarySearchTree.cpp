/*=============================================================================
#     FileName: 98-ValidateBinarySearchTree.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 06:30:58
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
        bool isValidBST(TreeNode *root, int minVal, int maxVal) {
            if (!root) {
                return true;
            }
            int val = root->val;
            if (val > maxVal || val < minVal) {
                return false;
            }
            if ((root->left && root->left->val >= val) || (root->right && root->right->val <= val)) {
                return false;
            }
            return isValidBST(root->left, minVal, val - 1) && isValidBST(root->right, val + 1, maxVal);
        }
        bool isValidBST(TreeNode* root) {
            return isValidBST(root, INT_MIN, INT_MAX);
        }
};
