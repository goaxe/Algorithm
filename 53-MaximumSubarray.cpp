/*=============================================================================
#     FileName: 53-MaximumSubarray.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 12:33:52
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int len = nums.size();
            int globalMax = INT_MIN, curMax = 0;
            for (int i = 0; i < len; i ++) {
                globalMax = max(globalMax, nums[i]);
            }
            if (globalMax <= 0) {
                return globalMax;
            }
            for (int i = 0; i < len; i ++) {
                curMax = max(0, curMax + nums[i]);
                globalMax = max(globalMax, curMax);
            }
            return globalMax;
        }
};

int main() {
    int num[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums;
    for (int i = 0; i < (int)(sizeof(num)/sizeof(int)); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
}
