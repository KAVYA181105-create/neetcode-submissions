class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i = 0; i<tasks.size() ; i++){
            freq[tasks[i]-'A']++;
        }
        int time=0;
        priority_queue<int> pq;
        for(auto i : freq){
            if(i>0){
            pq.push(i);}
        }
        while(!pq.empty()){
            vector<int> temp ;
            for(int i = 1; i<=n+1 ; i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }
            for(int& i : temp){
                if(i>0){
                pq.push(i);
                } 
            }
            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time +=n+1;
            }
        }
        return time;
    }
};
