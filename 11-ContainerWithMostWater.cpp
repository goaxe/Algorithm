/*=============================================================================
#     FileName: 11-ContainerWithMostWater.cpp
#         Desc: AC, 24ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 14:08:23
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int len = height.size(), globalMax = 0, left = 0, right = len - 1;
            while (left < right) {
                globalMax = max(globalMax, min(height[left], height[right]) * (right - left));
                if (height[left] <= height[right]) {
                    left ++;
                } else {
                    right --;
                }
            }
            return globalMax;
        }
};

int main() {
    vector<int> height;
    height.push_back(1);
    height.push_back(1);
    Solution solution;
    cout << solution.maxArea(height) << endl;
    return 0;
}
