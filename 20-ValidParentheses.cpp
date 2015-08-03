/*=============================================================================
#     FileName: 20-ValidParentheses.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 20:57:46
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isLeft(char c) {
            return c == '[' || c == '{' || c == '(';
        }

        bool isMatch(char c1, char c2) {
            return (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')');
        }


        bool isValid(string s) {
            stack<char> myStack;
            int len = s.length();
            for (int i = 0; i < len; i ++) {
                char c = s[i];
                if (isLeft(c)) {
                    myStack.push(c);
                } else {
                    if (myStack.empty()) {
                        return false;
                    } else {
                        char top = myStack.top();
                        if (!isMatch(top, c)) {
                            return false;
                        }
                        myStack.pop();
                    }
                }
            }
            return myStack.empty() ? true : false;
        }
};

int main() {
    Solution solution;
    cout << solution.isValid("{[)]") << endl;
    return 0;
}
