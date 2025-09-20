class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> s;

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && temp[s.top()] <= temp[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }

        return ans;
    }
};