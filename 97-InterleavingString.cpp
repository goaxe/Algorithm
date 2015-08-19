/*=============================================================================
#     FileName: 97-InterleavingString.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-20 06:21:04
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
            if (len1 + len2 != len3) {
                return false;
            }
            if (len1 == 0 || len2 == 0) {
                return len1 == 0 ? s2 == s3 : s1 == s3;
            }
            vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, true));
            for (int i = 1; i <= len1; i ++) {
                dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
            }
            for (int j = 1; j <= len2; j ++) {
                dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
            }
            for (int i = 1; i <= len1; i ++) {
                for (int j = 1; j <= len2; j ++) {
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
            return dp[len1][len2];
        }
};


int main() {
    Solution solution;
    cout << solution.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << solution.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
}
