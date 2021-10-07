// Interview Bit Sol
bool isPalindrome(string A) {
    int left = 0;
    int right = A.size()-1;
    while(left < right) {
        if(A[left] != A[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int Solution::minCut(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    vector<int> result(n+1);
    result[n] = -1;
    for(int i=n-1;i>=0;i--) {
        result[i] = n-i-1;
        for(int j=i;j<n;j++) {
            if(isPalindrome(A.substr(i, j-i+1))) {
                result[i] = min(result[i], 1 + result[j+1]);
            }
        }
    }
    return result[0];
}


//Leetcode Sol

class Solution {
public:
int minCut(string s) {
    int n = s.length();
    
    vector<int> dp(n+1, 0);
    
	//initialize the dp array (the max cuts need for a string of length i to be palindrome is i-1)
    for(int i=0; i<=n; i++){
        dp[i] = i-1;
    }
    
    for(int k=0; k<n; k++){
        int i=k;
        int j=k;
        //expand for odd length
        for(; i>=0 && j<n && s[i] == s[j]; i--, j++){
		//since the substring between i and j is a palindrome, so we'll put a cut on the left side of the substring
            dp[j+1] = min(dp[j+1], dp[i]+1);
        }
        
        i=k-1;
        j=k;
        //expand for even length
        for(; i>=0 && j<n && s[i] == s[j]; i--, j++){
		//since the substring between i and j is a palindrome, so we'll put a cut on the left side of the substring
            dp[j+1] = min(dp[j+1], dp[i]+1);
        }
    }
    
    return dp[n];
}
};
