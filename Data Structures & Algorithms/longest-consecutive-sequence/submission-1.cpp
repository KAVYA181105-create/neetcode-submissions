class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //lets try using bucket sorting 
        if(nums.empty()){return 0;}
        sort(nums.begin(),nums.end());
        int count=0;
        int max=0;
        for(int i =0 ; i<nums.size()-1;i++){
            if(nums[i]+1==nums[i+1]){count++;}
            else if(nums[i]==nums[i+1]){continue;}
            else{
                max =std::max(max,count);
                count = 0;
            }
        }
        max =std::max(max,count);
        return max+1;
    }
};
