class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int x = newInterval[0], y = newInterval[1];
        int i = 0, n = intervals.size();
        vector<int> a(2,0);
        for (; i < n; i++) {
            a = {intervals[i][0], intervals[i][1]};
            // if current interval finishes before x, add it to res
            if (a[1] < x) res.push_back(a); 
            // else if current interval start after y, [x,y] would not affect rest intervals
            else if (a[0] > y) break;
            // else, there are overlap
            else {
                x = min(x, a[0]);
                y = max(y, a[1]);
            }
        }
        res.push_back({x, y});
        for (; i < n; i++) res.push_back(intervals[i]);
        return res;
    }
};
