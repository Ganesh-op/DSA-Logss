class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxlen = 0, left = 0, right = 0;
        int n = s.size();
        vector<int> mp(26,0);
        int maxf = 0;

        while(right<n){

            mp[s[right]-'A']++;
            maxf = max(maxf,mp[s[right]-'A']); //we dont need to adjust the maxf after decrementing left character, because maxf decrementing never changes our maxlen.

            if((right-left+1)-maxf>k){
                mp[s[left]-'A']--;       //decrement the frequency of the character at left pointer not right
                left++;
            }
  
            maxlen = max(maxlen,right-left+1);
            
            right++;
        }

        return maxlen;
    }
};