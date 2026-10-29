class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        queue<pair<int, int>> pacQueue;
        queue<pair<int, int>> altQueue;
        // Queue initialization: Top and Bottom borders
        for (int c = 0; c < cols; ++c) {
            pacQueue.push({0, c});
            pacific[0][c] = true;

            altQueue.push({rows - 1, c});
            atlantic[rows - 1][c] = true;
        }

        // Queue initialization: Left and Right borders
        for (int r = 0; r < rows; ++r) {
            pacQueue.push({r, 0});
            pacific[r][0] = true;

            altQueue.push({r, cols - 1});
            atlantic[r][cols - 1] = true;
        }

        // BFS helper function
        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    // Check bounds, whether it's visited, and if water can flow inward (neighbor height >= current height)
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        };
        // Run BFS for both oceans
        bfs(pacQueue, pacific);
        bfs(altQueue, atlantic);
        // Collect cells that can reach both oceans
        vector<vector<int>> result;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};