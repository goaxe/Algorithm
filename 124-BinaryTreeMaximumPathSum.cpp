/*=============================================================================
#     FileName: 124-BinaryTreeMaximumPathSum.cpp
#         Desc: AC, 40ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-28 21:48:29
#      History:
=============================================================================*/

#include <leetcode.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int getMax(TreeNode * root, int &result) {
            if (!root) {
                return 0;
            }
            int left = getMax(root->left, result), right = getMax(root->right, result), ret = root->val + max(0, left) + max(0, right);
            result = max(ret, result);
            return max(0, max(left, right)) + root->val;

        }
        int maxPathSum(TreeNode * root) {
            if (!root) {
                return 0;
            }
            int result = INT_MIN;
            getMax(root, result);

            return result;
        }
};
