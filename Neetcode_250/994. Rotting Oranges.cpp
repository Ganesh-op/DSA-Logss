class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        int mins = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;
        int directions[4][2] ={{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while(!q.empty()){
            auto [row, col] = q.front().first;
            int rot = q.front().second;
            q.pop();
            mins = max(mins, rot);

            for(auto direction : directions){
                int nr = direction[0] + row;
                int nc = direction[1] + col;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({{nr, nc}, mins+1});
                }
            }
        }

        if(fresh == 0) return mins;
        return -1;
    }
};