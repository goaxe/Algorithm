/*=============================================================================
#     FileName: 135-Candy.cpp
#         Desc: AC, 40ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-08-30 11:03:01
#      Version: 0.0.1
#   LastChange: 2015-08-30 11:03:01
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int candy(vector<int>& ratings) {
            if (ratings.empty()) {
                return 0;
            }
            int len = ratings.size(), result = 0;
            vector<int> nums(len, 1);

            for (int i = 1; i < len; i ++) {
                if (ratings[i] > ratings[i - 1]) {
                    nums[i] = nums[i - 1] + 1;
                }
            }
            for (int i = len - 2; i >= 0; i --) {
                if (ratings[i] > ratings[i + 1]) {
                    nums[i] = max(nums[i], nums[i + 1] + 1);
                }
            }

            for (int i = 0; i < len; i ++) {
                result += nums[i];
            }
            return result;
        }
};

int main() {
    Solution solution;
    int nums[] = {1, 2, 3, 4, 1, 2, -1};
    vector<int> ratings;
    for (int i = 0; i < (int) sizeof(nums) / (int) sizeof(int); i ++) {
        ratings.push_back(nums[i]);
    }
    cout << solution.candy(ratings) << endl;
    return 0;
}
