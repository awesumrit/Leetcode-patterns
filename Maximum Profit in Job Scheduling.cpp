class Solution {
    typedef pair<int, int> pii;
    
public:
    
    static bool comp(const pii& t1, const pii& t2){
        return abs(t1.first) < abs(t2.first) || (abs(t1.first) == abs(t2.first) && t1.first < 0);
    } // if a startTime is equal to an endTime, the endTime comes first
    
    
    int jobScheduling(const vector<int>& startTime, const vector<int>& endTime, vector<int>& profit) {
        vector<pii> timestamp;
        for(int i = 0; i < startTime.size(); ++i) timestamp.push_back({startTime[i], i}); // positive means startTime
        for(int i = 0; i < endTime.size(); ++i) timestamp.push_back({-endTime[i], i}); // negative means endTime
		
        sort(timestamp.begin(), timestamp.end(), comp);
        
        int maxPrevious = 0, res = 0;
        for(const pii& t: timestamp)
            // now profit[timestamp[i].second] stores the max profit if we choose from 0 to i, and the i-th job must be included
            if (t.first > 0){
                profit[t.second] += maxPrevious;
                res = max(res, profit[t.second]);
            }
            else 
                maxPrevious = max(maxPrevious, profit[t.second]);
        
        return res;
    }
};
