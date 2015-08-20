/*=============================================================================
#     FileName: 107-BinaryTreeLevelOrderTraversalII.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 09:50:36
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
        vector<vector<int> > levelOrderBottom(TreeNode* root) {
            vector<vector<int> > result;
            vector<int> ret;
            queue<TreeNode *> nodeQueue;
            if (!root) {
                return result;
            }
            nodeQueue.push(root);
            int count = 1;

            while (!nodeQueue.empty()) {
                TreeNode *node = nodeQueue.front();
                nodeQueue.pop();
                ret.push_back(node->val);
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
                count --;
                if (count == 0) {
                    count = nodeQueue.size();
                    result.push_back(ret);
                    ret.clear();
                }
            }
            reverse(result.begin(), result.end());
            return result;
        }
};
