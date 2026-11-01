class Solution {
private:
    void bfs(int node , int n ,vector<vector<int>>& adjList,vector<int>& visited){
        visited[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto adj : adjList[temp] ){
                if(!visited[adj]){
                    visited[adj] = 1;
                    q.push(adj);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0);
        int count =0; 
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                bfs(i,n,adjList,visited);
                count++;
            }
        }
        return count;
    }
};