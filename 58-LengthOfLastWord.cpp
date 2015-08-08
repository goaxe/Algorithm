/*=============================================================================
#     FileName: 58-LengthOfLastWord.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 16:28:36
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int lengthOfLastWord(string s) {
            s.erase(s.find_last_not_of(" ") + 1);
            int len = s.length(), index = len - 1;
            if (len == 0) {
                return 0;
            }
            while (index >= 0 && s[index] != ' ') {
                index --;
            }
            return len - index - 1;
        }
};

int main() {
    Solution solution;
    
    cout << solution.lengthOfLastWord("hell world") << endl;
    cout << solution.lengthOfLastWord("  world  ") << endl;
    cout << solution.lengthOfLastWord(" hell world ") << endl;

}
