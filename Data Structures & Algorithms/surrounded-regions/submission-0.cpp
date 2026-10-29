
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& visited) {

        visited[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O' &&
                visited[nrow][ncol] == 0) {

                dfs(nrow, ncol, board, visited);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        if (n == 0) return;

        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // First row
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && visited[0][i] == 0) {
                dfs(0, i, board, visited);
            }
        }

        // Last row
        for (int i = 0; i < m; i++) {
            if (board[n-1][i] == 'O' && visited[n-1][i] == 0) {
                dfs(n-1, i, board, visited);
            }
        }

        // First column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0) {
                dfs(i, 0, board, visited);
            }
        }

        // Last column
        for (int i = 0; i < n; i++) {
            if (board[i][m-1] == 'O' && visited[i][m-1] == 0) {
                dfs(i, m-1, board, visited);
            }
        }

        // Convert enclosed O's into X's
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (board[row][col] == 'O' &&
                    visited[row][col] == 0) {
                    board[row][col] = 'X';
                }
            }
        }
    }
};
