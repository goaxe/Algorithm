/*=============================================================================
#     FileName: 106-ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
#         Desc: AC, 32ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 09:41:53
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
        TreeNode *buildTree(vector<int> &inorder, int iStart, int iEnd, vector<int> &postorder, int pStart, int pEnd) {
            if (pStart > pEnd) {
                return NULL;
            }
            TreeNode *root = new TreeNode(postorder[pEnd]);
            int val = root->val, pos = iStart;
            while (inorder[pos] != val) {
                pos ++;
            }
            int leftNum = pos - iStart;
            root->left = buildTree(inorder, iStart, pos - 1, postorder, pStart, pStart + leftNum - 1);
            root->right = buildTree(inorder, pos + 1, iEnd, postorder, pStart + leftNum, pEnd - 1);
            return root;
        }

        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        }
};
