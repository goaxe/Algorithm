/*=============================================================================
#     FileName: 129-SumRootToLeafNumbers.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-29 14:45:00
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
        void dfs(TreeNode *root, vector<int> &nums, int &result) {
            nums.push_back(root->val);
            if (!root->left && !root->right) {
                int ret = 0;
                for (auto num : nums) {
                    ret = ret * 10 + num;
                }
                result += ret;
                nums.pop_back();
                return ;
            }
            if (root->left) {
                dfs(root->left, nums, result);
            }
            if (root->right) {
                dfs(root->right, nums, result);
            }
            nums.pop_back();
        }
        int sumNumbers(TreeNode* root) {
            if (!root) {
                return 0;
            }
            vector<int> nums;
            int result = 0;
            dfs(root, nums, result);
            return result;
        }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution solution;
    cout << solution.sumNumbers(root) << endl;
    return 0;
}
