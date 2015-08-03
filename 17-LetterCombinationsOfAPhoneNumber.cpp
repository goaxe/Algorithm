/*=============================================================================
#     FileName: 17-LetterCombinationsOfAPhoneNumber.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 17:43:08
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void dfs(string ret, string &digits, map<char, string> &numMap, vector<string> &result) {
            if (ret.length() == digits.length()) {
                result.push_back(ret);
                return ;
            }
            string str = numMap[digits[ret.length()]];
            for (int i = 0; i < (int)str.length(); i ++) {
                dfs(ret + str[i], digits, numMap, result);
            }
        }

        vector<string> letterCombinations(string digits) {
            map<char, string> numMap;
            numMap['2'] = "abc";
            numMap['3'] = "def";
            numMap['4'] = "ghi";
            numMap['5'] = "jkl";
            numMap['6'] = "mno";
            numMap['7'] = "pqrs";
            numMap['8'] = "tuv";
            numMap['9'] = "wxyz";
            vector<string> result;
            if (digits.length() == 0) {
                return result;
            }
            dfs("", digits, numMap, result);
            return result;
        }
};

int main() {
    Solution solution;
    vector<string> result = solution.letterCombinations("23");
    for (int i = 0; i < (int)result.size(); i ++) {
        cout << result[i] << endl;
    }
    return 0;
}
