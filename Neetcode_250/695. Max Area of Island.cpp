class Solution {
public:
    void dfs(int x, int y, int &ans, vector<vector<int>>& grid) {
        grid[x][y] = 2;
        ans++;

        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == 1) {
                dfs(newX, newY, ans, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int temp = 0;
                if(grid[i][j] == 1){
                    dfs(i, j, temp, grid);
                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }

private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int m;
    int n;
};