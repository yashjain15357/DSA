class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char , pair<int , bool> > mp;
        int count = 0;
        for(int i = 0 ; i<s.size() ; i++){
            mp[s[i]].first = i;
            mp[s[i]].second = true;

            
            int j = i+1;
            int temp = 1;
            while(j < s.size()){
                if(!mp[s[j]].second){
                    mp[s[j]].first = j;
                    mp[s[j]].second = true;
                    temp++;
                }
                else{
                    i = mp[s[j]].first;
                    mp.clear();
                    break;
                }
                j++;
                
            }
            count = max(count , temp);
        }
        return count;


        
        
        
        
    }
};