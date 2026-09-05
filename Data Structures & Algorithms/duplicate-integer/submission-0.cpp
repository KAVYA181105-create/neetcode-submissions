class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> v1;
        for ( int i =0 ; i< nums.size() ; i++ ){
            if (v1.count(nums[i])) return true;
            v1.insert(nums[i]);
       }
       return false;
    }
};