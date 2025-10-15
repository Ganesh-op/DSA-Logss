class Solution {
public:
static bool cmp(vector<int> &a , vector<int> &b){
    return a[1]<b[1];
}
    bool carPooling(vector<vector<int>>& v, int cap) {
        sort(v.begin(),v.end(),cmp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int ans=v[0][0],tot=v[0][0],n = v.size();
        pq.push({v[0][2],tot});
        for(int i =1;i<n;i++){
            while(!pq.empty() && v[i][1]>=pq.top().first)
            {tot-=pq.top().second;pq.pop();}
            tot+=v[i][0];
            pq.push({v[i][2],v[i][0]});
            ans=max(ans,tot);
        }if(cap>=ans){return true;}return false;
    }
};