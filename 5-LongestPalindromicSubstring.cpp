/*=============================================================================
#     FileName: 5-LongestPalindromicSubstring.cpp
#         Desc: AC, 124ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 20:51:09
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    string longestPalindrome(string s) {
        string str = "$";
        int len = s.length(), idx = 1;
        if (len <= 1) {
            return s;
        }
        for (int i = 0; i < len; i ++) {
            str = str + s[i] + '#';
        }
        len = len * 2 + 1;
        vector<int> palindrome(len, 0);
        for (int i = 2; i < len; i ++) {
            int px = max(min(palindrome[2 * idx - i], idx + palindrome[idx] - i), 0);
            while (/*i + px + 1 < len && i - px - 1 >= 0 && */str[i + px + 1] == str[i - px - 1]) {
                px ++;
            }
            palindrome[i] = px;
        }
        int maxIndex = 0;
        for (int i = 0; i < len; i ++) {
            if (palindrome[i] > palindrome[maxIndex]) {
                maxIndex = i;
            }
        }
        string tmp = str.substr(maxIndex - palindrome[maxIndex], 2 * palindrome[maxIndex] + 1), result = "";
        for (int i = 0; i < (int)tmp.length(); i ++) {
            if (tmp[i] != '#') {
                result += tmp[i];
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("bb") << endl;
}
