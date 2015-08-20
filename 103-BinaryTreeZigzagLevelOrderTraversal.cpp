/*=============================================================================
#     FileName: 103-BinaryTreeZigzagLevelOrderTraversal.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 08:50:58
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
        vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
            vector<vector<int> > result;
            vector<int> ret1;
            vector<TreeNode *> vec1, vec2;
            if (!root) {
                return result;
            }
            vec1.push_back(root);
            bool zigZag = true;
            while (!vec1.empty()) {
                ret1.clear();
                for (int i = 0; i < (int) vec1.size(); i ++) {
                    TreeNode *node = vec1[i];
                    ret1.push_back(node->val);
                    if (node->left) {
                        vec2.push_back(node->left);
                    }
                    if (node->right) {
                        vec2.push_back(node->right);
                    }
                }
                if (!zigZag) {
                    reverse(ret1.begin(), ret1.end());
                }
                result.push_back(ret1);
                zigZag = !zigZag;
                vec1.swap(vec2);
                vec2.clear();
            }
            return result;
        }
};
