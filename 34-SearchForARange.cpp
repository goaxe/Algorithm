/*=============================================================================
#     FileName: 34-SearchForARange.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-06 21:48:50
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result(2, -1);
            if (nums.empty()) {
                return result;
            }
            int len = nums.size(), start = 0, end;
            while (start < len && nums[start] != target) {
                start ++;
            }
            if (start == len) {
                return result;
            }
            end = start;
            while (end + 1 < len && nums[end + 1] == target) {
                end ++;
            }
            result[0] = start;
            result[1] = end;
            return result;
        }
};

int main() {
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    Solution solution;
    vector<int> result = solution.searchRange(nums, 8);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
