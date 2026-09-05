class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using hash map 
        unordered_map <int,int> mp;
        for (int i = 0 ; i<nums.size() ; i++){
            int currentNum =nums[i];
            int complement = target - currentNum;
            if(mp.count(complement)){
                return {mp[complement],i};
            }
            mp[currentNum]=i;
        }
        return{};
             
    }
};
