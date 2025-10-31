class Solution {
public:
#define ll long long
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector<ll> dp(s.size()+1, 0);
        dp[0]=1;
        for(int i = 1; i < s.size() ; ++i) {
            if(s[i] == '0') {
                if(s[i-1] > '2' or s[i-1] == '0') return 0;
                else {
                    if(i==1) dp[i] = dp[i-1];
                    else {
                        if(s[i-2] == '1' or (s[i-2] =='2' and s[i-1] <= '6')) {
                            dp[i] = dp[i-1] + (dp[i-2]-dp[i-1]) ;
                        }
                        else dp[i] = dp[i-1];
                    } 
                }
            }
            else {
                if(s[i-1] > '2' or s[i-1] == '0') dp[i] = dp[i-1];
                else {
                    if(s[i] > '6' and s[i-1] == '2') dp[i] = dp[i-1];
                    else {
                        if(dp[i-1] == 1) dp[i] = dp[i-1] + 1;
                        else dp[i] += (dp[i-1]*2);
                        if(i>=2) dp[i]+=(dp[i-2]-dp[i-1]); 
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};