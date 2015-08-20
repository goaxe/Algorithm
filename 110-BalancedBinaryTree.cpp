/*=============================================================================
#     FileName: 110-BalancedBinaryTree.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 10:30:52
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
        int height(TreeNode *root) {
            if (!root) {
                return 0;
            }
            return max(height(root->left), height(root->right)) + 1;
        }

        bool isBalanced(TreeNode* root) {
            if (!root) {
                return true;
            }
            return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) < 2;
        }
};
