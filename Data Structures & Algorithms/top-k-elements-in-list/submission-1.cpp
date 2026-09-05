class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> res;
        for(int i =0 ; i<nums.size() ; i++){
            res[nums[i]]++;
        }
        vector<int> result;
        for(int j =k ;j>0 ; j--){
            auto curr = max_element(res.begin(),res.end(),
            [](const auto& a, const auto& b) 
            { return a.second < b.second; });
            result.push_back(curr->first);
            res.erase(curr->first);
        }
        return result;
    }
};
