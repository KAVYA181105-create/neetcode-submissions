class Solution {
public:
    vector<vector<string>> result;
    bool isPalindrome(string s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right])
                return false;
            left++;
            right--;}
        return true;}
    void solve(string s, int start, vector<string>& temp) {
        if(start == s.size()) {
            result.push_back(temp);
            return;}
        for(int i = start; i < s.size(); i++) {
            if(isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                solve(s, i + 1, temp);
                temp.pop_back();}}}
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, 0, temp);
        return result;}};