class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int cost_sum = accumulate(cost.begin(), cost.end(), 0);
        if(cost_sum>gas_sum){
            return -1;
        }


        int tank_val = 0;
        
        int index = -1;
        int m = INT_MAX;
        
        for(int i = 0  ; i<gas.size() ; i++){
            
            if(m>tank_val){
                m = tank_val;
                index = i;
            }
            
            tank_val = (tank_val+gas[i])-cost[i];
        }
        
        return index;

        
    }
};