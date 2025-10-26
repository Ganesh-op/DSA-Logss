class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1)
            return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(degree[i] == 1)
                q.push(i);
        }

        int remaining_nodes = n;
        while(remaining_nodes > 2) {
            int node_count = q.size();
            remaining_nodes = remaining_nodes - node_count;
            for(int i=0; i<node_count; i++) {
                int node = q.front();
                q.pop();

                for(int nbr: adj[node]) {
                    degree[nbr]--;
                    if(degree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};