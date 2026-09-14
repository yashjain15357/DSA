class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int cost_sum = accumulate(cost.begin(), cost.end(), 0);
        if(cost_sum>gas_sum){
            return -1;
        }


        int tank_val = 0;
        vector<int>ans;
        for(int i = 0  ; i<gas.size() ; i++){
            ans.push_back(tank_val);
            cout<<tank_val;
            tank_val = (tank_val+gas[i])-cost[i];
        }
        int m = INT_MAX;
        int index = -1;
        for(int i = 0 ; i<ans.size() ; i++){
            if(m>ans[i]){
                m = ans[i];
                index = i;
            }
        }
        return index;

        
    }
};