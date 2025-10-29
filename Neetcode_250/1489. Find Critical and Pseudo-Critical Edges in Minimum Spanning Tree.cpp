
// bhai bahut sahi qs to revise all concept of Graph(Dsu, mst,kruskal,adding edges)

 //<-----------------DSU------------------------------------>
class dsu {
public:
    vector<int> parent, size, rank;

    dsu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionSize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    void unionRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] == rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
        }
    }
};
//<-----------------DSU End------------------------------------>
class Solution {
public:
    int n;


 // adj-->{wt,{u,v,idx}}
// pair<int,tuple<>>   
    vector<pair<int, tuple<int, int, int>>> adj;


//<-----------------Kruskal------------------------------------>
    int kruskal(int b1, int b2) {
        dsu d(n);
        int wt = 0, edge = 0;

        for (auto &it : adj) {
            int cost = it.first;
            auto t = it.second;
            int u = get<0>(t);
            int v = get<1>(t);

            if ((u == b1 && v == b2) || (v == b1 && u == b2))
                continue; 

            if (d.findParent(u) != d.findParent(v)) {
                d.unionRank(u, v);
                wt += cost;
                edge++;
            }
        }

        return (edge == n - 1) ? wt : INT_MAX; 
    }

//<-----------------Kruskal-End------------------------------------>

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        this->n = n;
        adj.clear();

        for (int i = 0; i < edges.size(); i++) {
            adj.push_back({edges[i][2], {edges[i][0], edges[i][1], i}});
        }

        vector<vector<int>> ans(2);//0->cticical-edge, 1->pseudo-edge
        sort(adj.begin(), adj.end()); // based on wt-->low wt will come  first

        int mst = kruskal(-1, -1); 

        for (int i = 0; i < edges.size(); i++) {
            int wt = kruskal(edges[i][0], edges[i][1]);

            
  // if(removing this edge cost us more mst)-->crictical
               // else if adding this edge give us same mst-->psudeo
            if (wt > mst) {
                ans[0].push_back(i); 
            } else {
                 // forcly adding this edge
                 // yes, u can re-use kruskal, i'm not using here
                dsu d(n);
                d.unionRank(edges[i][0], edges[i][1]);
                int wt1 = edges[i][2], edge = 1;

                for (auto &it : adj) {
                    int cost = it.first;
                    auto t = it.second;
                    int u = get<0>(t);
                    int v = get<1>(t);

                    if (d.findParent(u) != d.findParent(v)) {
                        d.unionRank(u, v);
                        wt1 += cost;
                        edge++;
                    }
                }

                if (edge == n - 1 && wt1 == mst) {
                    ans[1].push_back(i); 
                }
            }
        }

        return ans;
    }
};