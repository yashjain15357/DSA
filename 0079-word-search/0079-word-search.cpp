class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i) {
        // Base case: found all letters
        if (i == word.size()) return true;

        // Boundary checks & character matching check
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[i]) {
            return false;
        }

        // Mark cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 directions (Up, Down, Left, Right)
        bool found = dfs(board, word, r + 1, c, i + 1) ||
                     dfs(board, word, r - 1, c, i + 1) ||
                     dfs(board, word, r, c + 1, i + 1) ||
                     dfs(board, word, r, c - 1, i + 1);

        // Backtrack: restore original character
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0] && dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};