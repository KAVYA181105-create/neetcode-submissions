class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> need(128, 0);
        // Store frequency of characters in t
        for (char c : t)
            need[c]++;
        int left = 0;
        int count = t.size();      // Characters still needed
        int minLen = INT_MAX;
        int start = 0;
        for (int right = 0; right < s.size(); right++) {
            // If this character is needed, reduce count
            if (need[s[right]] > 0)
                count--;
            // Include current character in window
            need[s[right]]--;
            // Window is valid
            while (count == 0) {
                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;}
                // Remove left character from window
                need[s[left]]++;
                // If it becomes required again, window is invalid
                if (need[s[left]] > 0)
                    count++;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);}
};