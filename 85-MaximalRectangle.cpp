/*=============================================================================
#     FileName: 85-MaximalRectangle.cpp
#         Desc: AC, 40ms prefect solution
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-12 10:04:59
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
            cout << "lar: " << largest << endl;
            return largest;
        }
        int maximalRectangle(vector<vector<char> >& matrix) {
            if (matrix.empty() || matrix[0].empty()) {
                return 0;
            }
            int m = matrix.size(), n = matrix[0].size(), result = 0;
            vector<int> dp(n, 0);
            for (int i = 0; i < m; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (matrix[i][j] == '1') {
                        dp[j] += 1;
                    } else {
                        dp[j] = 0;
                    }
                }
                result = max(result, largestRectangleArea(dp));
            }
            return result;
        }
};

