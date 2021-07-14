
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<3)
            return {};
        int ans = INT_MAX;
        int indi=0, indj=1, indk=2;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target) < ans)
                {
                    ans = min(ans, abs(sum-target));
                    indi = i; indj = j; indk = k;
                }
                if(sum>target)
                {
                    int val=nums[k];
                    k--;
                    while(k>=0 && val==nums[k])
                    {
                        k--;
                    }
                }
                else
                {
                    int val=nums[j];
                    j++;
                    while(j<n && val==nums[j])
                    {
                        j++;
                    }
                }
            }
        }
        return nums[indi]+nums[indj]+nums[indk];
    }
};
