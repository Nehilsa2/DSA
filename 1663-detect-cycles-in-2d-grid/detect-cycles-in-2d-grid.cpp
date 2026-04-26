class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[x][y] = true;

        int n = grid.size();
        int m = grid[0].size();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == grid[x][y]) {

                // If not visited → go deeper
                if (!vis[nx][ny]) {
                    if (dfs(nx, ny, x, y, grid, vis)) return true;
                }
                // If visited and not parent → cycle found
                else if (!(nx == px && ny == py)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, vis)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};