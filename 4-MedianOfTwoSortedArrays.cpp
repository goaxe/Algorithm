/*=============================================================================
#     FileName: 4-MedianOfTwoSortedArrays.cpp
#         Desc: AC, 44ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 20:02:37
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    double findKth(int nums1[], int len1, int nums2[], int len2, int k) {
        if (len1 == 0) {
            return nums2[k - 1];
        }
        if (len2 == 0) {
            return nums1[k - 1];
        }
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }
        if (k == len1 + len2) {
            return max(nums1[len1 - 1], nums2[len2 - 1]);
        }
        int a = min(len1, k / 2), b = min(k - a, len2);
        if (nums1[a - 1] == nums2[b - 1]) {
            if (a + b == k) {
                return nums1[a - 1];
            }
            return findKth(nums1 + a, len1 - a, nums2 + b, len2 - b, k - a - b);
        } else if (nums1[a - 1] > nums2[b - 1]) {
            return findKth(nums1, len1, nums2 + b, len2 - b, k - b);
        } else {
            return findKth(nums1 + a, len1 - a, nums2, len2, k - a);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int *num1 = new int[len1], *num2 = new int[len2];
        for (int i = 0; i < len1; i ++) {
            num1[i] = nums1[i];
        }
        for (int i = 0; i < len2; i ++) {
            num2[i] = nums2[i];
        }
        if ((len1 + len2) % 2 == 1) {
            return findKth(num1, len1, num2, len2, (len1 + len2 + 1) / 2);
        } else {
            return (findKth(num1, len1, num2, len2, (len1 + len2) / 2) + findKth(num1, len1, num2, len2, 1 + (len1 + len2) / 2)) / 2;
        }
    }
};

int main() {
    Solution solution;
    //int num1[] = {}, num2[] = {1};
    vector<int> nums1, nums2;
    nums2.push_back(1);
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
