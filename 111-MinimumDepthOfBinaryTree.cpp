/*=============================================================================
#     FileName: 111-MinimumDepthOfBinaryTree.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 10:42:47
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
        int minDepth(TreeNode* root) {
            if (!root) {
                return 0;
            }
            if (!root->left && !root->right) {
                return 1;
            }
            int left = root->left ? minDepth(root->left) : INT_MAX;
            int right = root->right ? minDepth(root->right) : INT_MAX;
            return min(left, right) + 1;
        }
};
