class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int ans=1;
        for(int i =0 ; i<nums.size() ; i++){
            for(int j =0 ; j<nums.size() ; j++){
                if(i==j){continue;}
                else {
                    ans = ans*nums[j];
                } 
            }
            result.push_back(ans);
            ans =1;
        }return result;
    }
};
