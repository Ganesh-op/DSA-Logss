class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        int ans =0;
        if(nums.size()<2)return nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1)count++;
            else if(nums[i+1]==nums[i]){}
            else {
                count=1;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};