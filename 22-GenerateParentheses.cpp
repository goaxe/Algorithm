/*=============================================================================
#     FileName: 22-GenerateParentheses.cpp
#         Desc: AC, 3ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 23:07:19
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    void dfs(string ret, int left, int right, int n, vector<string> &result) {
        if (left == n) {
            if (right == n) {
                result.push_back(ret);
                return ;
            } else {
                for (int i = 0; i < left - right; i ++) {
                    ret += ")";
                }
                result.push_back(ret);
                return ;
            }
        }
        dfs(ret + "(", left + 1, right, n, result);
        for (int i = 0; i < left - right; i ++) {
            ret += ")";
            dfs(ret + "(", left + 1, right + i + 1, n, result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n < 1) {
            return result;
        }
        dfs("", 0, 0, n, result);
        return result;
    }
};

int main() {
    Solution solution;
    for (int i = 1; i < 4; i ++) {
        vector<string> result = solution.generateParenthesis(i);
        cout << i << endl;
        for (int i = 0; i < (int)result.size(); i ++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
