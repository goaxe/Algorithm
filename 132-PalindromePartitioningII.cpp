/*=============================================================================
#     FileName: 132-PalindromePartitioningII.cpp
#         Desc: AC, 84ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-29 16:52:24
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int minCut(string s) {
            if (s == "" || s.length() == 1) {
                return 0;
            }
            int len = s.length();
            vector<vector<bool> > dp(len, vector<bool>(len, 0));
             vector<int> cut(len + 1, 0);
            for (int i = 0; i <= len; i ++) {
                cut[i] = len - i;
            }           
            for (int i = len - 1; i >= 0; i --) {
                for (int j = len - 1; j >= i; j --) {
                    if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                        dp[i][j] = true;
                        cut[i] = min(cut[i], 1 + cut[j + 1]);
                    }
                }
            }
            return cut[0] - 1;
        }
};

int main() {
    Solution solution;
    cout << solution.minCut("aab") << endl;
    cout << solution.minCut("aabbcc") << endl;


}
