class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair <int , pair<int,int> > > pq;
        int n = points.size();
        for(int i = 0 ; i< n ; i ++ ){
            int distance = (points[i][0]* points[i][0]) + (points[i][1]*points[i][1]);
            pq.push({distance,{points[i][0] , points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> result;
        while(pq.size()>0){
            result.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return result;
    }
};
