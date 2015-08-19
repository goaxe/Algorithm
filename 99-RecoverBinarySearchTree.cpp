/*=============================================================================
#     FileName: 99-RecoverBinarySearchTree.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 06:41:12
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
    private:
        TreeNode *first, *second;
    public:
        bool isValidBST(TreeNode *root, int minVal, int maxVal) {
            if (!root) {
                return true;
            }
            int val = root->val;
            if (val > maxVal || val < minVal) {
                if (first) {
                    second = root;
                } else {
                    first = root;
                }
                return false;
            }
            if ((root->left && root->left->val >= val) || (root->right && root->right->val <= val)) {
                return false;
            }
            return isValidBST(root->left, minVal, val - 1) && isValidBST(root->right, val + 1, maxVal);
        }

        void recoverTree(TreeNode* root) {
            first = NULL;
            second = NULL;
            isValidBST(root, INT_MIN, INT_MAX);
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
};
