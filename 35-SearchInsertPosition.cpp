/*=============================================================================
#     FileName: 35-SearchInsertPosition.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-06 21:55:44
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            if (nums.empty()) {
                return 0;
            }
            int len = nums.size(), index = 0;
            while (index < len && nums[index] < target) {
                index ++;
            }
            return index;
        }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);

    Solution solution;
    cout << solution.searchInsert(nums, 5) << endl;
    cout << solution.searchInsert(nums, 2) << endl;
    cout << solution.searchInsert(nums, 7) << endl;
    cout << solution.searchInsert(nums, 0) << endl;
}
