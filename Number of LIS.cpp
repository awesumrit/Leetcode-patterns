class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n+1, INT_MAX);
        vector<vector< pair<int,int> >> LISbylen(n+1);

        dp[0] = INT_MIN;
        LISbylen[0] = { {1, INT_MIN} };

        int max_len = 1;
        for(auto &ele: nums){

            int len = lower_bound(dp.begin(), dp.end(), ele) - dp.begin();
            dp[len] = ele;

            int ele_count = 0;
            for(auto &[count, last]: LISbylen[len-1])
                if(ele>last) ele_count+=count;

            LISbylen[len].push_back({ele_count, ele});
            max_len = max(max_len, len);

        }

        int num_lis = 0;
        for(auto &[count, last]: LISbylen[max_len])
            num_lis += count;

        return num_lis;

    }
};
