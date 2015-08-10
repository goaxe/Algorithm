/*=============================================================================
#     FileName: 78-Subsets.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-10 10:27:23
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void dfs(vector<int> ret, int level, vector<int> &nums, vector<vector<int> > &result) {
            int len = nums.size(), end = level;
            if (level == len) {
                result.push_back(ret);
                return ;
            }
            while (end + 1 < len && nums[end + 1] == nums[end]) {
                end ++;
            }
            dfs(ret, end + 1, nums, result);
            for (int i = 0; i < end - level + 1; i ++) {
                ret.push_back(nums[level]);
                dfs(ret, end + 1, nums, result);
            }
        }
        vector<vector<int> > subsets(vector<int>& nums) {
            vector<vector<int> > result;
            vector<int> ret;
            if (nums.empty()) {
                return result;
            }
            sort(nums.begin(), nums.end());
            dfs(ret, 0, nums, result);
            return result;
        }
};

int main() {
    vector<int> nums;
    for (int i = 1; i <= 3; i ++) {
        nums.push_back(i);
    }
    Solution solution;
    vector<vector<int> > result = solution.subsets(nums);
    for (int i = 0; i < (int) result.size(); i ++) {
        for (int j = 0; j < (int) result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
