class Solution {
public:
    int bfs(int row , int col , vector<vector<int>>& visited ,vector<vector<int>>& grid ){
        visited[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        int are=1;
        while(!q.empty()){
            int row=q.front().first;
            int col =q.front().second;
            q.pop();
            int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, -1, 1};
            for(int i = 0 ; i<4 ; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m &&grid[nrow][ncol]==1 &&!visited[nrow][ncol]){
                    visited[nrow][ncol]= 1 ;
                    q.push({nrow,ncol});
                    are++;
                }
            }
        }
        return are;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)return 0;
        int m = grid[0].size();
        vector<vector<int>> visited(n ,vector<int>(m,0));
        int area = 0;
        for(int row =0 ; row<n ;row++){
            for(int col = 0 ;col<m ;col++){
                if(!visited[row][col]&&grid[row][col]==1){
                    area = max(area,bfs(row,col,visited,grid));
                }
            }
        }
    return area;
    }
};
