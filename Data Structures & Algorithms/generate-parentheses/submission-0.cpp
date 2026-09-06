class Solution {
public:
    vector<string> result ;
    void solve(int n , int open ,int  close , string current){
        if(open == n && close == n){
            result.push_back(current);
        }
        //for open bracket
        if(open < n){
            current.push_back('(');
            solve(n,open+1,close,current);
            current.pop_back();
        }
        if(close < open){
            current.push_back(')');
            solve(n,open,close+1,current);
            current.pop_back();
        }
    } 
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
    return result;
    }};
