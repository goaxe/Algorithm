/*=============================================================================
#     FileName: 108-ConvertSortedArrayToBinarySearchTree.cpp
#         Desc: AC, 20ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 09:53:56
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
        TreeNode *sortedArrayToBST(vector<int> &nums, int low, int high) {
            if (low > high) {
                return NULL;
            }
            int mid = (low + high) >> 1;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBST(nums, low, mid - 1);
            root->right = sortedArrayToBST(nums, mid + 1, high);
            return root;
        }
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return sortedArrayToBST(nums, 0, nums.size() - 1);
        }
};
