/*=============================================================================
#     FileName: 38-CountAndSay.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-07 09:23:21
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        string generateNext(string s) {
            string result = "";
            int len = s.length(), start = 0, end;
            while (start < len) {
                end = start;
                while (end + 1 < len && s[end + 1] == s[end]) {
                    end ++;
                }
                result = result + (char)('0' + end - start + 1) + s[start];
                start = end + 1;
            }
            return result;
        }
        string countAndSay(int n) {
            if (n == 1) {
                return "1";
            }
            return generateNext(countAndSay(n - 1));
        }
};

int main() {
    Solution solution;
    for (int i = 1; i < 10; i ++) {
        cout << solution.countAndSay(i) << endl;
    }
}
