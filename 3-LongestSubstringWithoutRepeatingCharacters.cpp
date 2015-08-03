/*=============================================================================
#     FileName: 3-LongestSubstringWithoutRepeatingCharacters.cpp
#         Desc: AC, 88ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 17:47:24
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int len = s.length();
            vector<long> pos(128, -1);
            long maxLen = 0, curLen = 0;
            for (int i = 0; i < len; i ++) {
                char c = s[i];
                int num = (int)c;
                if (pos[num] == -1) {
                    pos[num] = i;
                    curLen ++;
                    maxLen = max(maxLen, curLen);
                } else {
                    int prevPos = pos[num];
                    for (int j = 0; j < 128; j ++) {
                        if (pos[j] < prevPos) {
                            pos[j] = -1;
                        }
                        pos[num] = i;
                        curLen = i - prevPos;
                        maxLen = max(maxLen, curLen);
                    }
                }
            }
            return maxLen;
        }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
    return 0;
}
