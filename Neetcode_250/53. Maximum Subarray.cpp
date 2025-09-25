class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currnt = 0;
        int maxsum = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(currnt<0){
                currnt = 0;
            }
            currnt = currnt + nums[i];
            maxsum = max(currnt,maxsum);
        }  
        return maxsum;
    }
};