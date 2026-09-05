class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        unordered_map<char,int> mp2;
        for(auto i : s1){
            mp[i]++;
        }
        //here we will use a sliding window of fixed size of lenght of s1
        int l =0;
        int r = s1.size()-1;
        while(r<s2.size()){
            mp2.clear();
            for(int i =l ; i <= r ; i++){
                mp2[s2[i]]++;
            }
            if(mp == mp2){return true;}
            l++;
            r++;
        } 
        return false;
    }
};
