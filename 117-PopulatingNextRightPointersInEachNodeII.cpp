/*=============================================================================
#     FileName: 117-PopulatingNextRightPointersInEachNodeII.cpp
#         Desc: AC, 40ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 20:05:58
#      History:
=============================================================================*/

#include <leetcode.h>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
        void connect(vector<TreeLinkNode *> nodes) {
            vector<TreeLinkNode *> tmp;
            if (nodes.empty()) {
                return ;
            }
            int len = nodes.size();
            if (len == 1) {
                connect(nodes[0]);
                return ;
            }
            for (int i = 0; i < len; i ++) {
                TreeLinkNode *node = nodes[i];
                if (node->left) {
                    tmp.push_back(node->left);
                }
                if (node->right) {
                    tmp.push_back(node->right);
                }
                node->next = i == len - 1 ? NULL : nodes[i + 1];
            }
            connect(tmp);
        }
        void connect(TreeLinkNode *root) {
            if (!root) {
                return ;
            }
            root->next = NULL;
            vector<TreeLinkNode *> nodes;
            if (root->left) {
                nodes.push_back(root->left);
            }
            if (root->right) {
                nodes.push_back(root->right);
            }
            connect(nodes);
        }
};
