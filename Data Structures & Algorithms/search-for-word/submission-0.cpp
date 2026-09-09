class Solution {
public:
    bool result = false;
    void solve(int row, int column,
               vector<vector<char>>& board,
               string& word,
               string& current,
               int i) {

        // Complete word found
        if(current == word) {
            result = true;
            return;
        }

        // Out of bounds
        if(row < 0 || column < 0 ||
           row >= board.size() ||
           column >= board[0].size()) {
            return;
        }

        // Character doesn't match
        if(board[row][column] != word[i]) {
            return;
        }

        // Mark current cell
        char temp = board[row][column];
        board[row][column] = '#';

        // Choose current character
        current.push_back(temp);

        // DOWN
        solve(row + 1, column, board, word, current, i + 1);

        // UP
        solve(row - 1, column, board, word, current, i + 1);

        // RIGHT
        solve(row, column + 1, board, word, current, i + 1);

        // LEFT
        solve(row, column - 1, board, word, current, i + 1);

        // Backtrack
        current.pop_back();
        board[row][column] = temp;
    }

    bool exist(vector<vector<char>>& board, string word) {

        string current = "";

        for(int row = 0; row < board.size(); row++) {

            for(int column = 0; column < board[0].size(); column++) {

                if(board[row][column] == word[0]) {

                    solve(row, column,
                          board, word,
                          current, 0);

                    if(result)
                        return true;
                }
            }
        }

        return false;
    }
};