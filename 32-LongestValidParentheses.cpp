/*=============================================================================
#     FileName: 32-LongestValidParentheses.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-06 15:24:53
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int longestValidParentheses(string s) {
            if (s == "") {
                return 0;
            }
            int len = s.length(), result = 0;
            vector<int> dp(len, 0);
            for (int i = len - 2; i >= 0; i --) {
                if (s[i] == ')') {
                    dp[i] = 0;
                } else {
                    int j =  i + 1 + dp[i + 1];
                    if (j < len && s[j] == ')') {
                        dp[i] = dp[i + 1] + 2;
                        if (j + 1 < len) {
                            dp[i] += dp[j + 1];
                        }
                    }
                }
                result = max(result, dp[i]);
            }
            return result;
        }


        //AC, 16ms
        int longestValidParenthesesII(string s) {
            if (s == "") {
                return 0;
            }
            int len = s.length(), result = 0, start = 0, end;
            vector<bool> visited(len, false);
            stack<int> indexs;
            for (int i = 0; i < len; i ++) {
                if (s[i] == '(') {
                    indexs.push(i);
                } else {
                    if (!indexs.empty()) {
                        visited[i] = true;
                        visited[indexs.top()] = true;
                        indexs.pop();
                    }
                }
            }
            while (start < len) {
                while (start < len && !visited[start]) {
                    start ++;
                }
                if (start >= len) {
                    break;
                }
                end = start;
                while (end + 1 < len && visited[end + 1]) {
                    end ++;
                }
                result = max(end - start + 1, result);
                start = end + 1;
            }
            cout << "result: " << result << endl;
            return result;
        }
        //TLE
        int longestValidParenthesesI(string s) {
            if (s == "") {
                return 0;
            }
            int len = s.length(), result = 0;
            vector<int> deta(len, 0);
            vector<int> status(len, 0);
            for (int i = 0; i < len; i ++) {
                for (int j = i; j < len; j ++) {
                    deta[i] = 0;
                    status[i] = 0;
                }
                for (int j = i; j < len; j ++) {
                    if (s[j] == '(') {
                        deta[j] = i == j ? 1 : deta[j - 1] + 1;
                    } else {
                        deta[j] = i == j ? -1 : deta[j - 1] - 1;
                    }
                    if (i == j) {
                        status[j] = deta[j] > 0 ? 1 : 0;
                    } else {
                        if (status[j - 1] == 2) {
                            status[j] = deta[j] > 0 ? 1 : 0;
                        } else if (status[j - 1] == 1) {
                            if (deta[j] == 0) {
                                status[j] = 2;
                                result = max(result, j - i + 1);
                            } else if (deta[j] > 0) {
                                status[j] = 1;
                            } else {
                                status[j] = 0;
                            }
                        } else {
                            status[j] = 0;
                        }
                    }
                    if (status[j] == 0) {
                        break;
                    }
                }
            }
            return result;
        }
};

int main() {
    Solution solution;
    cout << solution.longestValidParentheses("()()") << endl;
    return 0;
}
