class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zero_position;
        int col = matrix[0].size();
        int row = matrix.size();

        for(int i = 0 ; i<row; i++){
            for(int j = 0 ; j<col ; j++){
                if(matrix[i][j]==0){
                    zero_position.push_back({i ,j});
                }
            }
        }
        for(auto p : zero_position){
            int r = p[0];
            int c = p[1];
            for(int i = 0 ; i<col ; i++){
                matrix[r][i] =0;
            }
            for(int i = 0 ; i<row ; i++){
                matrix[i][c] =0;
            }

        }
        
        
    }
};