class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            // Push opening brackets
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);}
            else {
                // If stack is empty, no matching opening bracket
                if (st.empty()) {
                    return false;}
                // Check if the top matches the current closing bracket
                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{')) {
                    st.pop();}
                else {
                    return false;}}}
        // If stack is empty, all brackets matched
        return st.empty();}
};