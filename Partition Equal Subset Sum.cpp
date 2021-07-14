
class Solution {
public:
    int dp[201][10001];
    bool solve(vector<int>& v,int ind,int sum){
        if(sum==0) return true;
        if(ind==v.size()) return false;
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
		
		// if we dont choose current index
        bool res = solve(v,ind+1,sum);
		
		// if we choose current index
        if(v[ind]<=sum){
            res = res | solve(v,ind+1,sum-v[ind]);
        }
        return dp[ind][sum] = res;
    }
    
    bool canPartition(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        int  sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        if(sum%2) return false;
        return solve(v,0,sum/2);
    }
};
