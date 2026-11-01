class Solution {
private:
    bool dfs(int node ,int parent ,vector<int>& visited ,  vector<vector<int>>&adjList ){
        visited[node]=1;
        for(auto adj : adjList[node]){
            if(!visited[adj]){
                if( dfs(adj,node,visited,adjList)){
                  return true;
                }
            }
            else if(adj != parent){
                return true;
            }
        }
        return false;
        }
public:// i just need to check wheather there is a cycle or not if cyle then false if no cyle then true
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);
        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0);
        if (dfs(0, -1, visited, adjList)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};