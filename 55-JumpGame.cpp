/*=============================================================================
#     FileName: 55-JumpGame.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 13:19:39
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if (nums.empty() || nums.size() < 2) {
                return true;
            }
            int len = nums.size(), index = 0;
            while (true) {
                if (nums[index] == 0) {
                    return false;
                }
                if (index + nums[index] >= len - 1) {
                    return true;
                }
                int nextIndex, maxDistance = -1;
                for (int i = 1; i <= nums[index]; i ++) {
                    if (nums[index + i] + i > maxDistance) {
                        maxDistance = nums[index + i] + i;
                        nextIndex = index + i;
                    }
                }
                index = nextIndex;
            }
            return true;
        }
};
int main() {
    int num[] = {3,2,1,0,4};

    vector<int> nums;
    for (int i = 0; i < int(sizeof(num)/sizeof(int)); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    cout << solution.canJump(nums) << endl;
    return 0;
}
