/*=============================================================================
#     FileName: 6-ZigZagConversion.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 09:29:11
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int len = s.length();
        string result = "";
        for (int i = 0; i < numRows; i ++) {
            int j = i;
            if (i == 0 || i == numRows - 1) {
                while (j < len) {
                    result += s[j];
                    j += 2 * numRows - 2;
                }
            }
            while (j < len) {
                result += s[j];
                j += 2 * numRows - 2 * i - 2;
                if (j >= len) {
                    break;
                }
                result += s[j];
                j += 2 * i;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.convert("paypalishiring", 1) << endl;
    return 0;
}
