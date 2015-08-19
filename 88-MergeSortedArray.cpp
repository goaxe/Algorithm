/*=============================================================================
#     FileName: 88-MergeSortedArray.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-18 07:17:11
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            for (int i = 0; i < m; i ++) {
                nums1[m + n - i - 1] = nums1[m - i - 1];
            }
            int i = n, j = 0, cur = 0;
            while (i < m + n && j < n) {
                if (nums1[i] < nums2[j]) {
                    nums1[cur ++] = nums1[i ++];
                } else {
                    nums1[cur ++] = nums2[j ++];
                }
            }
            while (i < m + n) {
                nums1[cur ++] = nums1[i ++];
            }
            while (j < n) {
                nums1[cur ++] = nums2[j ++];
            }
        }
};


int main() {
    vector<int> nums1(9, 0), nums2(5, 0);
    nums1[0] = -1;
    nums1[2] = 1;
    nums1[3] = 1;
    nums2[0] = -1;
    nums2[2] = 2;
    nums2[3] = 2;
    nums2[4] = 3;
    Solution solution;
    solution.merge(nums1, 4, nums2, 5);
    for (int i = 0; i < 9; i ++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
}
