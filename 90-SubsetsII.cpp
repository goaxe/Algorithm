/*=============================================================================
#     FileName: 90-SubsetsII.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-18 07:58:00
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void dfs(vector<int> ret, int level, vector<int> &nums, vector<vector<int> > &result) {
            int len = nums.size();
            if (level == len) {
                result.push_back(ret);
                return ;
            }
            int start = level;
            while (start + 1 < len && nums[start + 1] == nums[level]) {
                start ++;
            }
            dfs(ret, start + 1, nums, result);
            for (int i = level; i <= start; i ++) {
                ret.push_back(nums[i]);
                dfs(ret, start + 1, nums, result);
            }
        }
        vector<vector<int> > subsetsWithDup(vector<int>& nums) {
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
    vector<int> nums(3, 2);
    nums[0] = 1;
    for (int i = 0; i < (int) nums.size(); i ++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    Solution solution;
    vector<vector<int> > result = solution.subsetsWithDup(nums);
    for (int i = 0; i < (int) result.size(); i ++) {
        for (int j = 0; j < (int) result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
