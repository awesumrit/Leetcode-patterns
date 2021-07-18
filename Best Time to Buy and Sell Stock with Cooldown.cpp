class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int dp[n+1][3];
        dp[0][0] = -prices[0]; //buy state
        dp[0][1] = 0; //sell state
        dp[0][2] = 0; //cooldown state
        
        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]); //buy 
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            
        }
        
        return dp[n-1][1];
    }
};


// public int maxProfit(int[] prices) {
//     int n = prices.length;
//     int bs=-prices[0];
//     int ss=0;
//     int cs=0;
    
//     for(int i=1;i<n;i++){
//         int b=0,s=0,c=0;
        
//         b = Math.max(bs , cs-prices[i]);
//         s = Math.max(ss , bs+prices[i]);
//         c = Math.max(ss,cs);
        
//         bs=b;
//         ss=s;
//         cs=c;
//     }
//     return ss;
// }
