/*=============================================================================
#     FileName: 131-PalindromePartitioning.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-29 16:15:39
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void dfs(vector<string> &ret, int index, const vector<vector<bool> > &dp, const string &s, vector<vector<string> > &result) {
            int len = s.length();
            if (index == len) {
                result.push_back(ret);
                return ;
            }
            for (int i = index; i < len; i ++) {
                if (dp[index][i]) {
                    ret.push_back(s.substr(index, i - index + 1));
                    dfs(ret, i + 1, dp, s, result);
                    ret.pop_back();
                }
            }
        }
        vector<vector<string> > partition(string s) {
            vector<vector<string> > result;
            vector<string> ret;
            if (s == "") {
                return result;
            }
            int len = s.length();
            vector<vector<bool> > dp(len, vector<bool>(len, false));
            for (int i = len - 1; i >= 0; i --) {
                for (int j = len - 1; j >= i; j --) {
                    if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
            dfs(ret, 0, dp, s, result);
            return result;
        }
};

int main() {
    Solution solution;
    vector<vector<string> > result = solution.partition("aabbbb");
    for (int i = 0; i < (int) result.size(); i ++) {
        for (int j = 0; j < (int) result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
