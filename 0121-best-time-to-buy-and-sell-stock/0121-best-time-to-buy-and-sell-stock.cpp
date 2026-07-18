class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int ans = 0;
        for(int i = 0 ; i<prices.size(); i++){
            // ans = max(ans , sell - buy);
            if(buy > prices[i]){
                sell = prices[i];
                buy = prices[i];
            }
            if(sell<prices[i]){
                sell = prices[i];
                ans = max(ans , sell - buy);
            }
        }
        return ans;
        


        
    }
};