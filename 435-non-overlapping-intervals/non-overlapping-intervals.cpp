class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if (intervals.empty()) return 0;

        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int lastEnd = INT_MIN;
        int count = 0;

        for (auto &it : intervals) {
            if (it[0] >= lastEnd) {
                count++;
                lastEnd = it[1];
            }
        }

        return n - count;
    }
};