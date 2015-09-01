/*=============================================================================
#     FileName: 144-BinaryTreePreorderTraversal.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-09-01 08:20:12
#      Version: 0.0.1
#   LastChange: 2015-09-01 08:20:12
#      History:
#               0.0.1 | Jian Huang | init
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
        void preOrder(TreeNode *root, vector<int> &result) {
            if (!root) {
                return ;
            }
            result.push_back(root->val);
            preOrder(root->left, result);
            preOrder(root->right, result);
        }

        vector<int> preorderTraversalII(TreeNode* root) {
            vector<int> result;
            preOrder(root, result);
            return result;
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode *> nodeStack;
            while (root || !nodeStack.empty()) {
                while (root) {
                    result.push_back(root->val);
                    nodeStack.push(root);
                    root = root->left;
                }
                if (!nodeStack.empty()) {
                    root = nodeStack.top();
                    nodeStack.pop();
                    root = root->right;
                }
            }
            return result;
        }
};
