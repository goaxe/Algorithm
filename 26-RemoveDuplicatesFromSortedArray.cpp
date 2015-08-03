/*=============================================================================
#     FileName: 26-RemoveDuplicatesFromSortedArray.cpp
#         Desc: AC, 28ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-03 20:30:25
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size(), current = nums[0], curLen = 1;
        for (int i = 1; i < len; i ++) {
            if (nums[i] != current) {
                nums[curLen ++] = nums[i];
                current = nums[i];
            }
        }
        return curLen;
    }
};
