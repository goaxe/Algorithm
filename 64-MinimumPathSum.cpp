/*=============================================================================
#     FileName: 64-MinimumPathSum.cpp
#         Desc: AC, 28ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 09:39:57
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i ++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 0; i < n; i ++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
