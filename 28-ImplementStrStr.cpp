/*=============================================================================
#     FileName: 28-ImplementStrStr.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-04 20:32:04
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void getNext(vector<int> &next, string str) {
            int len = next.size(), k = -1, j = 0;
            while (j < len - 1) {
                if (k == -1 || str[j] == str[k]) {
                    k ++;
                    j ++;
                    next[j] = k;
                } else {
                    k = next[k];
                }
            }
        }

        int strStr(string haystack, string needle) {
            int pLen = needle.length(), len = haystack.size();
            if (len < pLen) {
                return -1;
            }
            if (pLen == 0) {
                return 0;
            }
            vector<int> next(pLen, 0);
            next[0] = -1;
            getNext(next, needle);
            int i = 0, j = 0;
            while (i < len && j < pLen) {
                if (j == -1 || haystack[i] == needle[j]) {
                    i ++;
                    j ++;
                } else {
                    j = next[j];
                }
            }
            if (j == pLen) {
                return i - j;
            }
            return -1;
        }
};

int main() {
/*    string str = "abcdabd";*/
    //int len = str.length();
    //vector<int> next(len, 0);
    //next[0] = -1;
    /*cout << str << endl;*/
    Solution solution;
    cout << solution.strStr("abcdabd", "dab") << endl;
    cout << "abcdabd" << endl;
    cout << "dab" << endl;
    return 0;
}
