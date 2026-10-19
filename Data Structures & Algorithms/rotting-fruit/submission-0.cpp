class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        int minute = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                }
                else if (grid[row][col] == 1) {
                    fresh++;
                }
            }
        }
        int delrow[] = {0, 0, -1, 1};
        int delcol[] = {-1, 1, 0, 0};
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.push({nrow, ncol});
                    }
                }
            }
            
            minute++;
        }
        if (fresh > 0) {
            return -1;
        }
        return minute;
    }
};
