class Solution {
public:
    int maxArea(vector<int>& height) {
        // TLE because of n2 time complexity
        // int ans = 0;
        // for(int i = 0 ; i<height.size() ; i++){
        //     for(int j = i+1 ; j<height.size(); j++){
        //         int width = j-i;
        //         int high;
        //         if(height[j]<height[i]){
        //             high = height[j];
        //         }
        //         else{
        //             high = height[i];
        //         }
        //         ans = max(ans , width*high);

        //     }
        // }
        // return ans;

        int p1 = 0;
        int p2 = height.size()-1;
        int ans = 0;
        while(p1<p2){
            int width = p2-p1;
            int high;
                if(height[p1]<height[p2]){
                    high = height[p1];
                    p1++;
                }
                else{
                    high = height[p2];
                    p2--;
                }
            ans = max(ans , width*high);
            
        }
        return ans;
        
    }
};