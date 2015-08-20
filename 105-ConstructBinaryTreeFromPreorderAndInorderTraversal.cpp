/*=============================================================================
#     FileName: 105-ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
#         Desc: AC, 32ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 09:26:59
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
        TreeNode *buildTree(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd) {
            if (pStart > pEnd) {
                return NULL;
            }
            TreeNode *root = new TreeNode(preorder[pStart]);
            int val = root->val, pos = iStart;
            while (inorder[pos] != val) {
                pos ++;
            }
            int leftNum = pos - iStart;
            root->left = buildTree(preorder, pStart + 1, pStart + leftNum, inorder, iStart, pos - 1);
            root->right = buildTree(preorder, pStart + leftNum + 1, pEnd, inorder, pos + 1, iEnd);
            return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        }
};
