/*=============================================================================
#     FileName: 31-NextPermutation.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-06 15:02:17
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            if (nums.empty()) {
                return ;
            }
            int len = nums.size(), i = len - 1, j = len - 1;
            while (i > 0 && nums[i] <= nums[i - 1]) {
                i --;
            }
            if (i == 0) {
                while (i < j) {
                    swap(nums[i ++], nums[j --]);
                }
                return ;
            }
            i --;
            while (nums[j] <= nums[i]) {
                j --;
            }
            swap(nums[i], nums[j]);
            j = len - 1, i ++;
            while (i < j) {
                swap(nums[i ++], nums[j --]);
            }
            return ;
        }
};

int main() {
    vector<int> vec;
    for (int i = 0; i < 4; i ++) {
        vec.push_back(i);
    }
    Solution solution;
    for (int j = 0; j < 3; j ++) {
        solution.nextPermutation(vec);
        for (int i = 0; i < 4; i ++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

}
