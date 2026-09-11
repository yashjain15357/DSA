class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        for(int val : tickets){
            q.push(val);
        }
        int n = q.size();
        int ans = 0;
        while(true){
            int val = q.front();
            val--;
            ans++;
            q.pop();
            if(val>0){
                q.push(val);
            }
            k--;
            if(k<= -1 && val >0){
                k = q.size()-1;
            }
            else if(k<= -1 && val == 0){
                return ans;
            }

        }
        return ans;

    }
};