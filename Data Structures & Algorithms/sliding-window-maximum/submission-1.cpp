class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //sliding window of size k that starts at the left edge of array 
        int n = nums.size();
        int l = 0; 
        int r = k;
        int max =INT_MIN ;
        vector<int> result;
        while(r<=n){
            for(int i =l ; i < r ; i++){
                max = std::max(max,nums[i]);
            }
            result.push_back(max);
            max=INT_MIN;
            l++;
            r++;
        }
        return result;
    }
};
