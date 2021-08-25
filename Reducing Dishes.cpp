class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.rbegin(), s.rend());
        int currsum = 0, maxsum = 0, presum = 0;
        for(int i = 0; i < s.size(); i++) {
            presum += s[i];
            currsum += presum;
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};
