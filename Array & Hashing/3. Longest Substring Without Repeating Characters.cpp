class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int l = 0, r = 0, maxLen = 0;
        int n = s.length();

        while (r < n) {
            if (map.find(s[r]) != map.end()) {
                l = max(l, map[s[r]] + 1);
            }
            int len = r - l + 1;
            maxLen = max(maxLen, len);
            map[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};