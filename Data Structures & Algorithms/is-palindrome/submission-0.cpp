class Solution {
public:
    bool isPalindrome(string s) {
        // i only want the alphanumeric character 
        string s1;
        for(auto i :s ){
            if(isalnum(i)){
                i = tolower(i);
                s1.push_back(i);
            }
        }
        string s2 =s1;
        reverse(s1.begin(),s1.end());
        if(s1==s2){
            return true;
        }
        else {
            return false;
        }
        
    }
};
