/*=============================================================================
#     FileName: 113-PathSumII.cpp
#         Desc: AC, 24ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 10:56:50
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
        void dfs(TreeNode *root, vector<int> ret, int sum, vector<vector<int> > &result) {
            ret.push_back(root->val);
            sum -= root->val;
            if (!root->left && !root->right) {
                if (sum == 0) {
                    result.push_back(ret);
                }
                return ;
            }
            if (root->left) {
                dfs(root->left, ret, sum, result);
            }
            if (root->right) {
                dfs(root->right, ret, sum, result);
            }
        }

        vector<vector<int> > pathSum(TreeNode* root, int sum) {
            vector<vector<int> > result;
            vector<int> ret;
            if (!root) {
                return result;
            }
            dfs(root, ret, sum, result);
            return result;
        }
};
