/*=============================================================================
#     FileName: 45-JumpGameII.cpp
#         Desc: AC, 28ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 09:05:07
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int jump(vector<int>& nums) {
            if (nums.empty() || nums.size() == 1) {
                return 0;
            }
            int len = nums.size(), steps = 0, index = 0;
            while (true) {
                if (index + nums[index] >= len - 1) {
                    return steps + 1;
                }
                int maxDistance = 0, nextIndex;
                for (int i = 1; i <= nums[index]; i ++) {
                    if (index + i + nums[index + i] > maxDistance) {
                        nextIndex = index + i;
                        maxDistance = index + i + nums[index + i];
                    }
                }
                index = nextIndex;
                steps ++;
            }
        }
};

int main() {
    int num[] = {2, 3, 1, 1, 4};
    vector<int> nums;
    for (int i = 0; i < int(sizeof(num)/sizeof(int)); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    cout << solution.jump(nums) << endl;
}
