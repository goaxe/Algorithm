/*=============================================================================
#     FileName: 46-Permutations.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 09:22:17
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool nextPermutation(vector<int>& nums) {
            int len = nums.size(), i = len - 1, j = len - 1;
            while (i > 0 && nums[i] <= nums[i - 1]) {
                i --;
            }
            if (i == 0) {
                return false;
            }
            i --;
            while (nums[j] <= nums[i]) {
                j --;
            }
            swap(nums[i], nums[j]);
            j = len - 1, i ++;
            while (i < j) {
                swap(nums[i ++], nums[j --]);
            }
            return true;
        }
        vector<vector<int> > permute(vector<int>& nums) {
            vector<vector<int> > result;
            if (nums.empty()) {
                return result;
            }
            sort(nums.begin(), nums.end());
            result.push_back(nums);
            while (nextPermutation(nums)) {
                result.push_back(nums);
            }
            return result;
        }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution solution;
    vector<vector<int> > result = solution.permute(nums);
    for (int i = 0; i < (int)result.size(); i ++) {
        for (int j = 0; j < (int)result[0].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
