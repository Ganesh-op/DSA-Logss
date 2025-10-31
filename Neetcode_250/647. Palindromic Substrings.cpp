class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0, n = s.length(); i < n; ++i){
            for(int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j) ++res;
            for(int j = 0; i - j - 1 >= 0 && i + j < n && s[i - j - 1] == s[i + j]; ++j) ++res;
        }
        return res;
    }
};