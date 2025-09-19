class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> res;
        for (int a : arr) {
            while (!res.empty() && res.back() > 0 && a < 0 && res.back() < -a)
                res.pop_back();
            if (!res.empty() && res.back() > 0 && a < 0 && res.back() == -a)
                res.pop_back();
            else if (res.empty() || a > 0 || res.back() < 0)
                res.push_back(a);
        }
        return res;
    }
};