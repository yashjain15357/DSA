class Solution {
public:
    bool rowCheck(int row , int col ,char val, vector<vector<char>>&board){
        for(int i = 0 ; i<9 ; i++){
            if(board[i][col] == val){
                return false;
            }
        }
        return true;

    }
    bool colCheck(int row , int col ,char val, vector<vector<char>>&board){
        for(int i = 0 ; i<9 ; i++){
            if(board[row][i] == val){
                return false;
            }
        }
        return true;

    }
    bool boxCheck(int row, int col, char val, vector<vector<char>>& board) {
        int boxstartrow = (row / 3) * 3;
        int boxstartcol = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxstartrow + i][boxstartcol + j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    bool fun(vector<vector<char>>&board){
       
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j]=='.'){
                    for(int k = '1' ; k<='9' ; k++ ){
                        bool rowval = rowCheck(i , j , k , board);
                        bool colval = colCheck(i , j , k , board);
                        bool boxval = boxCheck(i , j , k , board);
                        if(rowval && colval && boxval){
                            board[i][j] = k;
                            if(fun(board )) return true;
                            board[i][j] ='.';
                        }
                    }
                    return false;
                    
                }

            }
        }

        return true;



    }

    void solveSudoku(vector<vector<char>>& board) {
        fun(board);
  
    }
};