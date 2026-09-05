class Solution {
public:
int findMax(vector<int>piles){
    int n=piles.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,piles[i]);}
    return ans;}
// betow function return minimum rate of hour at which koko eat banana
long long totalhour(vector<int>piles,int h){ //h=midhour 
    long long totalh=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
    totalh+=(piles[i]+h-1)/h;}
    return totalh;}

int minEatingSpeed(vector<int>& piles, int h) {
        int low=1; int high=findMax(piles);
        while(low<=high){
           int  mid=low+(high-low)/2;
        long long Totalh= totalhour(piles,mid);
        if(Totalh<=h){
            //for minimus total hour rate we go to left and eliminate right half
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return low;
    }
};