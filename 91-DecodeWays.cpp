/*=============================================================================
#     FileName: 91-DecodeWays.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-18 21:54:04
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isLegal(char a, char b) {
            if (a > '2') {
                return false;
            }
            if (a == '2') {
                return b <= '6';
            }
            if (a == '0') {
                return false;
            }
            return true;
        }
        int numDecodings(string s) {
            int len = s.length();
            if (len == 0) {
                return 0;
            }
            if (len == 1) {
                return s[0] == '0' ? 0 : 1;
            }
            vector<int> dp(len + 1, 1);
            dp[1] = s[0] == '0' ? 0 : 1;
            for (int i = 2; i <= len; i ++) {
                dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
                dp[i] += isLegal(s[i - 2], s[i - 1]) ? dp[i - 2] : 0;
            }
            return dp[len];
        }

};

int main() {
    Solution solution;
    cout << solution.numDecodings("10") << endl;
}
