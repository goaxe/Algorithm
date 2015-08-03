/*=============================================================================
#     FileName: 1-TwoSum.cpp
#         Desc: AC, 24ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 17:26:10
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int len = nums.size();
            vector<int> result;
            map<int, int> indexMap;
            for (int i = 0; i < len; i ++) {
                int num = nums[i];
                if (indexMap.find(target - num) != indexMap.end()) {
                    result.push_back(indexMap[target - num] + 1);
                    result.push_back(i + 1);
                    return result;
                }
                indexMap.insert(pair<int, int>(num, i));
            }
            return result;
        }
};
