/*=============================================================================
#     FileName: 95-UniqueBinarySearchTreesII.cpp
#         Desc: AC, 24ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-19 07:26:58
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
        vector<TreeNode *> generateRecurse(vector<int> &nums, int low, int high) {
            vector<TreeNode *> result;
            if (low > high) {
                result.push_back(NULL);
                return result;
            }
            for (int i = low; i <= high; i ++) {
                vector<TreeNode *> leftNodes = generateRecurse(nums, low, i - 1), rightNodes = generateRecurse(nums, i + 1, high);
                for (int j = 0; j < (int)leftNodes.size(); j ++) {
                    for (int k = 0; k < (int)rightNodes.size(); k ++) {
                        TreeNode *root = new TreeNode(nums[i]); //this is very important, push_back copy the pointer, not the content...
                        root->left = leftNodes[j];
                        root->right = rightNodes[k];
                        result.push_back(root);
                    }
                }
            }
            return result;
        }

        vector<TreeNode*> generateTrees(int n) {
            vector<int> nums(n, 0);
            for (int i = 0; i < n; i ++) {
                nums[i] = i + 1;
            }
            return generateRecurse(nums, 0, n - 1);
        }
};

int main() {
    Solution solution;
    vector<TreeNode *> result = solution.generateTrees(3);
    for (int i = 0; i < (int) result.size(); i ++) {
        cout << result[i]->val;
        if (result[i]->right) {
            cout << " " << result[i]->right->val;
        }
        cout << endl;
    }
}
