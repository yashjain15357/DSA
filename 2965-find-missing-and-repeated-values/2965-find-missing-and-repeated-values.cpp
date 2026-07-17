class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2,0);
        int siz = grid[0].size()*grid[0].size();
        vector<int> temp(siz , 0);
        for(int i  =0 ; i<grid[0].size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++ ){
                temp[grid[i][j]-1]++;

            }
        }
        for(int i  = 0 ; i<siz ; i++){
            if(temp[i]>1){
                ans[0] = i+1;

            }
            if(temp[i]<1){
                ans[1] = i+1;

            }
        }
        return ans;


        
    }
};