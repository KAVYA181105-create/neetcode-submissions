class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0 ;
        int r  = s.size()-1;
        while(l<r){
           if(!isalnum(s[r])){
            r--;
            continue;
           }
           if(!isalnum(s[l])){
            l++;
            continue;
           }
           if(tolower(s[l])==tolower(s[r])){
            l++;
            r--;
            continue;
           }
           else if(s[l]!=s[r]){
            return false;
           }
          
        }
        return true;
    }
};
