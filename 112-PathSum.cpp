/*=============================================================================
#     FileName: 112-PathSum.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 10:50:27
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
        bool hasPathSum(TreeNode* root, int sum) {
            if (!root) {
                return false;
            }
            if (!root->left && !root->right) {
                return sum == root->val;
            }
            sum -= root->val;
            if (root->left && hasPathSum(root->left, sum)) {
                return true;
            }
            if (root->right && hasPathSum(root->right, sum)) {
                return true;
            }
            return false;
        }
};
