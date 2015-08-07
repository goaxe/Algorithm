/*=============================================================================
#     FileName: 33-SearchInRotatedSortedArray.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-06 21:20:09
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int searchBinary(vector<int> &nums, int low, int high, int target) {
            if (low > high) {
                return -1;
            }
            if (low == high) {
                return nums[low] == target ? low : -1;
            }
            int mid = (low + high) / 2, mVal = nums[mid], lVal = nums[low], hVal = nums[high];
            if (mVal == target) {
                return mid;
            } else if (mVal > hVal) {
                if (target == hVal) {
                    return high;
                } else if (target < hVal) {
                    return searchBinary(nums, mid + 1, high - 1, target);
                }
            } else if (lVal > mVal) {
                if (target > lVal) {
                    return searchBinary(nums, low + 1, mid - 1, target);
                } else if (target == lVal) {
                    return low;
                }
            }
            return max(searchBinary(nums, low, mid - 1, target), searchBinary(nums, mid + 1, high, target));
        }

        int search(vector<int>& nums, int target) {
            if (nums.empty()) {
                return -1;
            }
            return searchBinary(nums, 0, nums.size() - 1, target);
        }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(1);

    Solution solution;
    cout << solution.search(nums, 3) << endl;

}
