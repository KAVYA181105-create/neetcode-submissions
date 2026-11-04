class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 2147483647) {
                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};