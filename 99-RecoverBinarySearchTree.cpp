/*=============================================================================
#     FileName: 99-RecoverBinarySearchTree.cpp
#         Desc: AC, 56ms
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
    public:
        void travelInOrder(TreeNode *root, vector<TreeNode *> &result) {
            if (!root) {
                return ;
            }
            travelInOrder(root->left, result);
            result.push_back(root);
            travelInOrder(root->right, result);
        }

        void recoverTree(TreeNode* root) {
            vector<TreeNode *> nodes;
            travelInOrder(root, nodes);
            TreeNode *first = NULL, *second = NULL;
            for (int i = 1; i < (int) nodes.size(); i ++) {
                if (nodes[i]->val < nodes[i - 1]->val) {
                    if (!first) {
                        first = nodes[i - 1];
                        second = nodes[i];
                    } else {
                        second = nodes[i];
                    }
                }
            }
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
};
