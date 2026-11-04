class Solution {
public:// will be solving this using topological sort, kahn's algorithm
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto i : prerequisites){
            adjList[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i= 0 ; i<numCourses ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> answer;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            answer.push_back(node);
            for(auto adj : adjList[node]){
                indegree[adj]--;
                if(indegree[adj]==0){
                    q.push(adj);
                }
            }
        }
        if(answer.size()!=numCourses){
            return {};
        }
        return answer;
    }
};
