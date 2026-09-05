class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for( auto i : stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int temp = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            if(temp == temp2){
                continue;
            }
            else{
                int temp3 = abs(temp - temp2);
                pq.push(temp3);
            }
        }
        if(pq.size()==1){
        return pq.top();}
        else{
            return 0;
        }
    }
};
