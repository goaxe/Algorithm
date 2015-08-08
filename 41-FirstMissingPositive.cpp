/*=============================================================================
#     FileName: 41-FirstMissingPositive.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-07 16:41:55
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            if (nums.empty()) {
                return 1;
            }
            int len = nums.size(), index = 0;
            while (index < len) {
                if (nums[index] <= len && nums[index] > 0 && index != nums[index] - 1 && nums[index] != nums[nums[index] - 1]) {
                    swap(nums[index], nums[nums[index] - 1]);
                } else {
                    index ++;
                }
            }
            for (int i = 0; i < len; i ++) {
                cout << nums[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < len; i ++) {
                if (nums[i] != i + 1) {
                    return i + 1;
                }
            }
            return len + 1;
        }
};

int main() {
    vector<int> nums;
/*    nums.push_back(1);*/
    //nums.push_back(2);
    /*nums.push_back(0);*/
/*    nums.push_back(3);*/
    //nums.push_back(4);
    //nums.push_back(-1);
    /*nums.push_back(1);*/
    nums.push_back(1);
    nums.push_back(1);
    Solution solution;
    cout << solution.firstMissingPositive(nums) << endl;
    return 0;
}
