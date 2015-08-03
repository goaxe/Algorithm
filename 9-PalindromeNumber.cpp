/*=============================================================================
#     FileName: 9-PalindromeNumber.cpp
#         Desc: AC, 84ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 11:35:44
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int power(int x) {
        if (x == 0) {
            return 1;
        }
        int result = power(x / 2);
        result *= result;
        return x % 2 ? 10 * result : result;
    }

    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int len = 0, tmp = x;
        while (tmp) {
            tmp /= 10;
            len ++;
        }
        while (x) {
            int a = x % 10, b = x / power(len - 1);
            if (a != b) {
                return false;
            }
            x %= power(len - 1);
            x /= 10;
            len -= 2;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome(12121) << endl;
    cout << solution.isPalindrome(1212) << endl;
}
