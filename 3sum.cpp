class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<3)
            return {};
        vector<vector<int>>ans;
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
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});

                }
                if(sum>0)
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
        return ans;
    }
};
