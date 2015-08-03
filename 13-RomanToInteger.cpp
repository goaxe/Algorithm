/*=============================================================================
#     FileName: 13-RomanToInteger.cpp
#         Desc: AC, 116ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 15:05:28
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isPrefix(string s1, string s2) {
            if (s1.length() < s2.length()) {
                return false;
            }
            int len = s2.length();
            for (int i = 0; i < len; i ++) {
                if (s1[i] != s2[i]) {
                    return false;
                }
            }
            return true;
        }
        int romanToInt(string s) {
            map<string, int> numMap;
            numMap["M"] = 1000;
            numMap["CM"] = 900;
            numMap["D"] = 500;
            numMap["CD"] = 400;
            numMap["C"] = 100;
            numMap["XC"] = 90;
            numMap["L"] = 50;
            numMap["XL"] = 40;
            numMap["X"] = 10;
            numMap["IX"] = 9;
            numMap["V"] = 5;
            numMap["IV"] = 4;
            numMap["I"] = 1;
            string nums[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            int result = 0, index = 0;
            while (s != "") {
                while (isPrefix(s, nums[index])) {
                    result += numMap[nums[index]];
                    s = s.substr(nums[index].length(), s.length() - nums[index].length());
                }
                index ++;
            }
            return result;
        }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("XII") << endl;
    cout << solution.romanToInt("XXXIV") << endl;
    cout << solution.romanToInt("XCIII") << endl;
    return 0;
}
