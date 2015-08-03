/*=============================================================================
#     FileName: 27-RemoveElement.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-03 20:42:05
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size(), curLen = 0;
        for (int i = 0; i < len; i ++) {
            if (nums[i] != val) {
                nums[curLen ++] = nums[i];
            }
        }
        return curLen;
    }
};
