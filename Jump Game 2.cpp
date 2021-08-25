class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), ans=0;
        if(n == 1)
            return 0;
        int prev_dist=-1, curr_dist = nums[0];
        for(int i=0; i<n; i++){
            if(i>prev_dist){
                prev_dist = curr_dist;
                ans++;
            }
            if(prev_dist >= n-1)
                return ans;
            if(nums[i]+i > curr_dist)
                curr_dist = nums[i] + i;
        }
        
        return ans;
    }
};
