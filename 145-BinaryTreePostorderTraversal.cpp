/*=============================================================================
#     FileName: 145-BinaryTreePostorderTraversal.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-09-01 09:39:49
#      Version: 0.0.1
#   LastChange: 2015-09-01 09:39:49
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
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            if (!root) {
                return result;
            }
            stack<TreeNode *> nodeStack;
            TreeNode *prev = NULL, *cur = NULL;
            nodeStack.push(root);
            while (!nodeStack.empty()) {
                cur = nodeStack.top();
                if ((!cur->left && !cur->right) || (prev && (prev == cur->left || prev == cur->right))) {
                    result.push_back(cur->val);
                    nodeStack.pop();
                    prev = cur;
                } else {
                    if (cur->right) {
                        nodeStack.push(cur->right);
                    }
                    if (cur->left) {
                        nodeStack.push(cur->left);
                    }
                }
            }
            return result;
        }
};
