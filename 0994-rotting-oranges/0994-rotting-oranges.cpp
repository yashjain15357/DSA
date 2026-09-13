class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount = 0;
        queue<pair<int , int>>q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        if (freshCount == 0) return 0;
        int time = -1;
        while(!q.empty()){
            int n = q.size();
            time++;
            cout<<n;
            for(int i = 0 ; i<n ; i++){
                auto index = q.front();
                q.pop();
                int row = index.first;
                int col = index.second;
                
                int g = grid.size();
                int c = grid[0].size();
                if(row+1 < g && row+1 >=0 && col<c && col>=0 && grid[row+1][col]==1){
                    q.push({row+1 , col});
                    grid[row+1][col] =2;
                    freshCount--;
                }
                if(row-1 < g && row-1 >=0 && col<c && col>=0 && grid[row-1][col]==1){
                    q.push({row-1 , col});
                    grid[row-1][col] =2;
                    freshCount--;
                }
                if(row < g && row >=0 && col+1<c && col+1>=0 && grid[row][col+1]==1){
                    q.push({row , col+1});
                    grid[row][col+1] =2;
                    freshCount--;
                }
                if(row < g && row >=0 && col-1<c && col-1>=0 && grid[row][col-1]==1){
                    q.push({row , col-1});
                    grid[row][col-1] =2;
                    freshCount--;
                }
            }
        }
            return freshCount==0 ?time:-1;
        
        
    }
};