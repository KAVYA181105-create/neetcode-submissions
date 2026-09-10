class Solution {
public:
    vector<string> result;
    unordered_map<int, string> mp;
    void solve(string digits, int i, string current) {
        if(i == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mp[digits[i] - '0'];
        for(int j = 0; j < letters.size(); j++){
            current.push_back(letters[j]);
            solve(digits, i + 1, current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        
        }
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        solve(digits, 0, "");
        return result;}};

