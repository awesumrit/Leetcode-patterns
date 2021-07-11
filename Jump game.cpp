class Solution {
public:
    bool canJump(vector<int>& nums) {
        int t=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            t=max(t-1,nums[i]);
            if(t<=0)
                return false;
        }
        return true;
    }
};
