class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& visited, vector<int>& pathvisited){
        visited[node] = 1;
        pathvisited[node] = 1;
        for(auto adj : graph[node]){
            if(!visited[adj]){
                if(dfs(adj, graph, visited, pathvisited)){
                    return true;
                }
            }
            else if(pathvisited[adj]){
                return true;
            }
        }
        pathvisited[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto it : prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> pathvisited(numCourses, 0);

        for(int i = 0; i < numCourses; i++){

            if(!visited[i]){

                if(dfs(i, graph, visited, pathvisited)){
                    return false;
                }
            }
        }

        return true;
    }
};