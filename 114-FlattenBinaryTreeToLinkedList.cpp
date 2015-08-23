/*=============================================================================
#     FileName: 114-FlattenBinaryTreeToLinkedList.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 11:11:55
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
        void flatten(TreeNode* root) {
            if (!root) {
                return ;
            }
            while (root) {
                if (root->left) {
                    TreeNode *prev = root->left;
                    while (prev->right) {
                        prev = prev->right;
                    }
                    prev->right = root->right;
                    root->right = root->left;
                    root->left = NULL;
                }
                root = root->right;
            }
        }
};

int main() {
    Solution solution;
    TreeNode *node1 = new TreeNode(1);
    node1->left = new TreeNode(2);
    solution.flatten(node1);
    while (node1) {
        cout << node1->val << " ";
        node1 = node1->right;
    }
    cout << endl;
}
