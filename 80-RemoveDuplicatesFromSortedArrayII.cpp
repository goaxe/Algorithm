/*=============================================================================
#     FileName: 80-RemoveDuplicatesFromSortedArrayII.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-10 17:09:38
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size(), count = 1, curIndex = 1, curVal = nums[0];
        for (int i = 1; i < len; i ++) {
            if (nums[i] == curVal) {
                if (count == 1) {
                    count ++;
                    nums[curIndex ++] = curVal;
                }
            } else {
                count = 1;
                curVal = nums[i];
                nums[curIndex ++] = curVal;
            }
        }
        return curIndex;
    }
};

int main() {
    int num[] = {1,1,1,2,2,3};
    vector<int> nums;
    for (int i = 0; i < 6; i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    cout << solution.removeDuplicates(nums) << endl;
}
