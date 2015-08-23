/*=============================================================================
#     FileName: 115-DistinctSubsequences.cpp
#         Desc: AC, 20ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 19:55:39
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int numDistinct(string s, string t) {
            int len1 = s.length(), len2 = t.length();
            if (len1 < len2) {
                return 0;
            }
            vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
            for (int i = 0; i <= len1; i ++) {
                dp[i][0] = 1;
            }
            for (int j = 1; j <= len2; j ++) {
                dp[0][j] = 0;

            }
            for (int i = 1; i <= len1; i ++) {
                for (int j = 1; j <= len2; j ++) {
                    dp[i][j] = dp[i - 1][j] + ((s[i - 1] == t[j - 1]) ? dp[i - 1][j - 1] : 0);
                }
            }
            return dp[len1][len2];
        }
};
