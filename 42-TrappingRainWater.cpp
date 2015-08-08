/*=============================================================================
#     FileName: 42-TrappingRainWater.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-07 17:17:19
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void addBinary(vector<int> &height, vector<int> &mPoint, int low, int high, int &result) {
            cout << low << " " << high << endl;
            if (low >= high) {
                return ;
            }
            int first = height[mPoint[low]] > height[mPoint[low + 1]] ? low : low + 1;
            int second = height[mPoint[low]] > height[mPoint[low + 1]] ? low + 1: low;
            for (int i = low + 2; i <= high; i ++) {
                int fVal = height[mPoint[first]], sVal = height[mPoint[second]], iVal = height[mPoint[i]];
                if (iVal <= sVal) {
                    continue;
                } else  if (iVal >= fVal) {
                    second = first;
                    first = i;
                } else {
                    second = i;
                }
            }
            cout << "first second: " << first << " " << second << endl;
            int m = height[mPoint[second]], l = min(mPoint[first], mPoint[second]), h = max(mPoint[first], mPoint[second]);
            for (int i = l + 1; i < h; i ++) {
                result += max(0, m - height[i]);
            }
            addBinary(height, mPoint, low, min(first, second), result);
            addBinary(height, mPoint, max(first, second), high, result);

        }
        int trap(vector<int>& height) {
            if (height.empty() || height.size() < 3) {
                return 0;
            }
            int len = height.size(), result = 0, index = 0;
            vector<int> mPoint;
            while (index < len - 1) {
                while (index + 1 < len && height[index + 1] >= height[index]) {
                    index ++;
                }
                mPoint.push_back(index);
                while (index + 1 < len && height[index + 1] <= height[index]) {
                    index ++;
                }
            }
            for (int i = 0; i < (int)mPoint.size(); i ++) {
                cout << mPoint[i] << " ";
            }
            cout << endl;
            addBinary(height, mPoint, 0, mPoint.size() - 1, result);
            return result;
        }
};

int main() {
    //int nums[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int nums[] = {5, 4, 1, 2};
    vector<int> heights;
    for (int i = 0; i < int(sizeof(nums) / sizeof(int)); i ++) {
        heights.push_back(nums[i]);
    }

    Solution solution;
    cout << solution.trap(heights) << endl;
    return 0;
}
