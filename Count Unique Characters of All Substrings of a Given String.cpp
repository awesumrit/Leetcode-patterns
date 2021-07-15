#define mod 1000000007

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        
        if(n == 0)
            return 0;
        
        int occur[26][2]; // occur[i] -> last 2 occurences of character i + 'A'
        
        for(int i = 0 ; i < 26 ; i++){
            occur[i][0] = -1;
            occur[i][1] = -1;
        }
        
        long prev = 1;
        occur[s[0] - 'A'][1] = 0;
        
        long ans = prev;
        
        for(int i = 1 ; i < n ; i++){
            prev = prev + i + occur[s[i] - 'A'][0] - 2*occur[s[i] - 'A'][1];
            occur[s[i] - 'A'][0] = occur[s[i] - 'A'][1];
            occur[s[i] - 'A'][1] = i;
            
            prev %= mod;
            ans += prev;
            ans %= mod;
        }
        
        return ans % mod;
    }
};
