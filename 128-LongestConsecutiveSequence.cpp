/*=============================================================================
#     FileName: 128-LongestConsecutiveSequence.cpp
#         Desc: AC, 24ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-29 14:27:26
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }
            int globalMax = 0, curMax, diff;
            unordered_map<int, bool> numMap;
            for (auto num : nums) {
                numMap.insert(pair<int, bool>(num, false));
            }
            for (auto it = numMap.begin(); it != numMap.end(); it ++) {
                if (it->second) {
                    continue;
                }
                it->second = true;
                curMax = 1;
                diff = 1;
                while (numMap.count(it->first - diff)) {
                    numMap[it->first - diff] = true;
                    diff ++;
                    curMax ++;
                }
                diff = 1;
                while (numMap.count(it->first + diff)) {
                    numMap[it->first + diff] = true;
                    diff ++;
                    curMax ++;
                }   
                globalMax = max(curMax, globalMax);
            }
            return globalMax;
        }
};

int main() {
    int num[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums;
    for (auto n : num) {
        nums.push_back(n);
    }
    Solution solution;
    cout << solution.longestConsecutive(nums) << endl;
    return 0;
}
