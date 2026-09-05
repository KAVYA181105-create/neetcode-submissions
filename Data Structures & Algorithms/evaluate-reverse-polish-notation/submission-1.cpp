class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int result;
        int p = 0;
        int n = tokens.size();
        stack<int> st;
        while (p < n) {
            if (tokens[p] != "+" && tokens[p] != "-" && tokens[p] != "*" && tokens[p] != "/") {
                st.push(stoi(tokens[p]));
                p++;
            } else if (tokens[p] == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = x + y;
                st.push(z);
                p++;
            } else if (tokens[p] == "-") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = y - x;
                st.push(z);
                p++;
            } else if (tokens[p] == "*") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = x * y;
                st.push(z);
                p++;
            } else if (tokens[p] == "/") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = y / x;
                st.push(z);
                p++;
            } else {
                p++;
            }
        }
        result = st.top();
        return result;
    }
};
