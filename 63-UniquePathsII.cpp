/*=============================================================================
#     FileName: 63-UniquePathsII.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 09:27:14
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
            if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
                return 0;
            }
            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            vector<vector<int> > dp(m, vector<int>(n, 0));
            dp[0][0] = !obstacleGrid[0][0];
            for (int i = 1; i < m; i ++) {
                dp[i][0] = dp[i - 1][0] && !obstacleGrid[i][0];
            }
            for (int i = 1; i < n; i ++) {
                dp[0][i] = dp[0][i - 1] && !obstacleGrid[0][i];
            }
            for (int i = 1; i < m; i ++) {
                for (int j = 1; j < n; j ++) {
                    dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
                }
            }
            return dp[m - 1][n - 1];
        }
};

int main() {
    vector<vector<int> > obstacleGrid(3, vector<int>(3, 0));
    obstacleGrid[1][1] = 1;
    Solution solution;
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;

}
