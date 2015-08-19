/*=============================================================================
#     FileName: 94-BinaryTreeInorderTraversal.cpp
#         Desc: Ac, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-19 07:09:59
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
        void recurseTraversal(TreeNode *root, vector<int> &result) {
            if (!root) {
                return ;
            }
            recurseTraversal(root->left, result);
            result.push_back(root->val);
            recurseTraversal(root->right, result);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            recurseTraversal(root, result);
            return result;
        }
};
