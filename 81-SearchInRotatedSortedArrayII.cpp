/*=============================================================================
#     FileName: 81-SearchInRotatedSortedArrayII.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-10 17:24:25
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool searchBinary(vector<int> &nums, int low, int high, int target) {
            if (low > high) {
                return false;
            }
            if (low == high) {
                return nums[low] == target;
            }
            int mid = (high + low) >> 1, lVal = nums[low], mVal = nums[mid], hVal = nums[high];
            if (mVal == target) {
                return true;
            } else if (mVal > lVal && lVal > hVal && target < hVal) {
                return searchBinary(nums, mid + 1, high - 1, target);
            } else if (lVal > hVal && hVal > mVal && target < mVal) {
                return searchBinary(nums, low, mid - 1, target);
            }
            return searchBinary(nums, low, mid - 1, target) || searchBinary(nums, mid + 1, high, target);
            
        }
        bool search(vector<int>& nums, int target) {
            if (nums.empty()) {
                return false;
            }
            return searchBinary(nums, 0, nums.size() - 1, target);
        }
};
