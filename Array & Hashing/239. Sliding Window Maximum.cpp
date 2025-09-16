class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // stores indices in decreasing order of values
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            // Remove smaller elements from the back
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            // Remove elements out of this window
            while(!q.empty() && q.front() <= i - k) q.pop_front();
            // Push current element index
            q.push_back(i);
            // Store result once window is formed
            if(i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};