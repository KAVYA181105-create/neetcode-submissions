class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> result;
            int product =1;
            int count0 =0;
            for(auto& i :nums){
                if(i==0){count0++;}
                else{
                    product = product*i;
                }
            }
           
            if(count0>=2){return vector<int>(nums.size(), 0);}
            if(count0 ==1){
                    for(auto i :nums){
                        if(i==0){
                            result.push_back(product);
                        }
                        else{
                            result.push_back(0);
                        }
                    }
                    return result;
            }
            if(count0 ==0){ 
                for(auto i:nums){
                int ans = product/i;
                result.push_back(ans);
                }
            }
            return result;
    }
};
