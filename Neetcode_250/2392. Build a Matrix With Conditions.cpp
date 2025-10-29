class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r1, vector<vector<int>>& c1) {
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        set<vector<int>>r(r1.begin(),r1.end());
        set<vector<int>>c(c1.begin(),c1.end());
        vector<list<int>>graph(k+1);
        vector<int>indegree(k+1,0);
        for(auto ele : r){
            graph[ele[0]].push_back(ele[1]);
            indegree[ele[1]]++;
        }
        queue<int>qu;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                qu.push(i);
            }
        }
        int count = 0;
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            row[curr] = count;
            count++;
            for(auto ngh: graph[curr]){
                indegree[ngh]--;
                if(indegree[ngh]==0){
                    qu.push(ngh);
                }
            }
        }
        cout<<count<<endl;
        if(count!=k) return {};
        graph.clear();
        graph.resize(k+1);
        indegree.clear();
        indegree.resize(k+1);
        count = 0;
        for(auto ele : c){
            graph[ele[0]].push_back(ele[1]);
            indegree[ele[1]]++;
        }
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            col[curr] = count;
            count++;
            for(auto ngh: graph[curr]){
                indegree[ngh]--;
                if(indegree[ngh]==0){
                    qu.push(ngh);
                }
            }
        }
        if(count!=k) return {};
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            ans[row[i]][col[i]] = i;
        }
        return ans;
    }
};