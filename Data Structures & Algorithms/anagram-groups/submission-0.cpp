class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string , vector<string>> res;
        for( auto i : strs){
            string sortedI = i;
            sort(sortedI.begin(),sortedI.end());
            res[sortedI].push_back(i) ; 
        }
        vector<vector<string>> result;
        for ( auto j:res){
                result.push_back(j.second);
        }
        return result;
    }
};
