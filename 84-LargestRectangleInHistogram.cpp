/*=============================================================================
#     FileName: 84-LargestRectangleInHistogram.cpp
#         Desc: AC, 24ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-12 08:09:08
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int largestRectangleArea(vector<int>& height) {
            if (height.empty()) {
                return 0;
            }
            height.push_back(0); //important
            int len = height.size(), largest = 0;
            stack<int> hStack;
            for (int i = 0; i < len; i ++) {
                if (hStack.empty() || height[hStack.top()] <= height[i]) {
                    hStack.push(i);
                } else {
                    while (!hStack.empty() && height[hStack.top()] > height[i]) {
                        int index = hStack.top();
                        hStack.pop();
                        int width = hStack.empty() ? i : (i - hStack.top() - 1); //important
                        largest = max(largest, width * height[index]);
                    }
                    hStack.push(i);
                }
            }
            return largest;
        }
};

int main() {
    int nums[] = {5, 4, 1, 2};
    vector<int> height;
    for (int i = 0; i < 4; i ++) {
        height.push_back(nums[i]);
    }
    Solution solution;
    cout << solution.largestRectangleArea(height) << endl;

}
