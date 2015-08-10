/*=============================================================================
#     FileName: 71-SimplifyPath.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 16:14:08
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        string simplifyPath(string path) {
            path.erase(0, path.find_first_not_of("/"));
            path.erase(path.find_last_not_of("/") + 1);
            if (path == "") {
                return "/";
            }
            stack<string> dirStack;
            vector<string> dirVec;
            int len = path.length(), start = 0, end;
            while (start < len) {
                end = start;
                while (end + 1 < len && path[end + 1] != '/') {
                    end ++;
                }
                dirVec.push_back(path.substr(start, end - start + 1));
                while (end + 1 < len && path[end + 1] == '/') {
                    end ++;
                }
                start = end + 1;
            }
            len = dirVec.size();

            for (int i = 0; i < len; i ++) {
                string tmp = dirVec[i];
                if (tmp == ".") {
                    continue;
                } else if (tmp == "..") {
                    if (!dirStack.empty()) {
                        dirStack.pop();
                    }
                } else {
                    dirStack.push(tmp);
                }
            }
            if (dirStack.empty()) {
                return "/";
            }
            string result = "";
            while (!dirStack.empty()) {
                result = "/" + dirStack.top() + result;
                dirStack.pop();
            }
            return result;
        }
};

int main() {
    Solution solution;
    cout << solution.simplifyPath("/a/./b/../../c/") << endl;
}
