class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> v1(26,0);
        if(s.length()!= t.length()){
            return false;
        }
        else{
            for(char c : s){
                v1[c-'a']++;
            }
            for (char c : t){
                v1[c - 'a']--;
            }
            for(char c : v1){
                if(c!=0){return false;}}
        }
        return true;

    }
};
