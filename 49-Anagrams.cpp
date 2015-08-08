/*=============================================================================
#     FileName: 49-Anagrams.cpp
#         Desc: AC, 68ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 10:56:28
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<string> anagrams(vector<string>& strs) {
            map<string, int> anagram;
            vector<string> result;
            if (strs.empty()) {
                return result;
            }
            int len = strs.size();
            for (int i = 0; i < len; i ++) {
                string tmp = strs[i];
                sort(tmp.begin(), tmp.end());
                if (anagram.find(tmp) == anagram.end()) {
                    anagram[tmp] = i;
                } else {
                    if (anagram[tmp] >= 0) {
                        result.push_back(strs[anagram[tmp]]);
                        anagram[tmp] = -1;
                    }
                    result.push_back(strs[i]);
                }
            }
            return result;
        }
};
