/*=============================================================================
#     FileName: 75-SortColors.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 20:31:18
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            if (nums.empty()) {
                return ;
            }
            int len = nums.size(), left = -1, right = len, mid;
            while (left + 1 < len && nums[left + 1] == 0) {
                left ++;
            }
            while (right - 1 >= 0 && nums[right - 1] == 2) {
                right --;
            }
            if (right -left == 1) {
                return ;
            }
            mid = left + 1;
            while (mid < right) {
                if (nums[mid] == 0) {
                    if (mid == left + 1) {
                        mid ++;
                        left ++;
                    } else {
                        swap(nums[mid], nums[left + 1]);
                        left ++;
                    }
                } else if (nums[mid] == 1) {
                    mid ++;
                } else if (nums[mid] == 2) {
                    swap(nums[mid], nums[right - 1]);
                    right --;
                }
            }
        }
};

int main() {
    int num[] = {2,2,0,0,2,0,2,1,0};
    vector<int> nums;
    for (int i = 0; i < 9; i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    solution.sortColors(nums);
    for (int i = 0; i < 9; i ++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
