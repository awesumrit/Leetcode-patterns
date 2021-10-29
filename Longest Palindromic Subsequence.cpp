int Solution::solve(string A) {
    int n = A.size();
    int dp[n][n] = {0};
    int max_index = 0, max_len = 1;
    for(int i=0; i<n; i++)
        dp[i][i] = 1;

    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(A[i] == A[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }
    return dp[0][n-1];

}
