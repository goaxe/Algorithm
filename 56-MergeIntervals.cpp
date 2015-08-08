/*=============================================================================
#     FileName: 56-MergeIntervals.cpp
#         Desc: AC, 680ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 15:58:38
#      History:
=============================================================================*/

#include <leetcode.h>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class cmp {
    public:
        bool operator() (Interval a, Interval b) {
            if (a.start == b.start) {
                return a.end < b.end;
            }
            return a.start < b.start;
        }
};
class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval> result;
            if (intervals.empty()) {
                return result;
            }
            sort(intervals.begin(), intervals.end(), cmp());
            int len = intervals.size();
            Interval ret = intervals[0];
            for (int i = 1; i < len; i ++) {
                Interval tmp = intervals[i];
                if (tmp.start > ret.end) {
                    result.push_back(ret);
                    ret = tmp;
                } else {
                    ret.end = max(ret.end, tmp.end);
                }
            }
            result.push_back(ret);
            return result;

        }
};

int main() {
    Interval i1(1, 3);
    Interval i2(2, 6);
    Interval i3(8, 10);
    Interval i4(15, 18);

    vector<Interval> intervals;
    intervals.push_back(i4);
    intervals.push_back(i3);
    intervals.push_back(i2);
    intervals.push_back(i1);

    Solution solution;
    vector<Interval> result = solution.merge(intervals);
    for (int i = 0; i < (int) result.size(); i ++) {
        cout << result[i].start << " " << result[i].end << endl;
    }
    return 0;
}
