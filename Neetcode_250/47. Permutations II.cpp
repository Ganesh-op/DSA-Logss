class Solution {
public:
vector<vector<int>> ans;
map<vector<int> , int> m;
void fun(int j , vector<int> v , vector<int>& nums,vector<int> vis){
        int n = nums.size();
    if(v.size()==n){if(m[v]==0){ans.push_back(v);m[v]++;}return ; }
        for(int i =0 ;i<n;i++){
            if( vis[i]==0){
                v.push_back(nums[i]);
                vis[i]++;
                fun(i,v,nums,vis);
                v.pop_back();
                vis[i]--;
            }
        }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> v;
        vector<int> vis(n+1,0);
        fun(0,v,nums,vis);
        return ans;
    }
};