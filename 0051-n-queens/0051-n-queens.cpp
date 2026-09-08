class Solution {
public:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans,vector<bool>& cols, vector<bool>& mainDiag, vector<bool>& antiDiag) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if column or diagonals are under attack
            if (cols[col] || mainDiag[row - col + n] || antiDiag[row + col]) continue;

            // Place Queen
            board[row][col] = 'Q';
            cols[col] = mainDiag[row - col + n] = antiDiag[row + col] = true;

            // Recurse for next row
            solve(row + 1, n, board, ans, cols, mainDiag, antiDiag);

            // Backtrack (Reset state)
            board[row][col] = '.';
            cols[col] = mainDiag[row - col + n] = antiDiag[row + col] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false), mainDiag(2 * n, false), antiDiag(2 * n, false);
        
        solve(0, n, board, ans, cols, mainDiag, antiDiag);
        return ans;
    }
};