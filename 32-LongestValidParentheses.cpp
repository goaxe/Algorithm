/*=============================================================================
#     FileName: 32-LongestValidParentheses.cpp
#         Desc: 
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
    cout << solution.longestValidParentheses(")()())") << endl;
    return 0;
}
