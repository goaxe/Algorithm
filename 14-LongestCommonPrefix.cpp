/*=============================================================================
#     FileName: 14-LongestCommonPrefix.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 15:56:10
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int len = strs.size(), index = 0;
            string result = "";
            if (len == 0) {
                return result;
            }
            while (true) {
                char c = strs[0][index];
                for (int i = 0; i < len; i ++) {
                    if ((int)strs[i].length() == index || strs[i][index] != c) {
                        return result;
                    }
                }
                result += c;
                index ++;
            }
            

        }
};
