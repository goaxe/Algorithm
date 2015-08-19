/*=============================================================================
#     FileName: 93-RestoreIPAddresses.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-19 06:43:29
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isLegal(string &s) {
            if (s.length() > 1 && s[0] == '0') {
                return false;
            }
            int num = atoi(s.c_str());
            if (num >= 0 && num <= 255) {
                return true;
            }
            return false;
        }

        string vec2String(vector<string> &ret) {
            string result = ret[0];
            for (int i = 1; i < 4; i ++) {
                result += "." + ret[i];
            }
            return result;
        }
        void dfs(vector<string> ret, int level, string &s, vector<string> &result) {
            int len = ret.size(), sLen = s.length();
            if (len == 4) {
                if (level == sLen) {
                    result.push_back(vec2String(ret));
                }
                return ;
            }
            if (level == sLen) {
                return ;
            }
            for (int i = 1; i <= min(3, sLen - level); i ++) {
                string tmp = s.substr(level, i);
                if (isLegal(tmp)) {
                    ret.push_back(tmp);
                    dfs(ret, level + i, s, result);
                    ret.pop_back();
                }
            }
        }


        vector<string> restoreIpAddresses(string s) {
            vector<string> result, ret;
            dfs(ret, 0, s, result);
            return result;
        }
};

int main() {
    Solution solution;
    //vector<string> result = solution.restoreIpAddresses("25525511135");
    //vector<string> result = solution.restoreIpAddresses("0000");
    vector<string> result = solution.restoreIpAddresses("010010");
    for (int i = 0; i < (int) result.size(); i ++) {
        cout << result[i] << endl;
    }
}
