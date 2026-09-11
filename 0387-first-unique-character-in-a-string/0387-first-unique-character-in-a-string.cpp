class Solution {
public:
    int firstUniqChar(string s) {
        // //This is method solved by Unordered map
        // unordered_map<char , int>mp;
        // for(char ch : s){
        //     mp[ch]++;
        // }
        // for(int i  = 0 ; i<s.length() ; i++){
        //     if(mp[s[i]]==1){
        //         return i;
        //     }
        // }
        // return -1;

        unordered_map<char, int> freq;
        queue<pair<char, int>> q; // stores {character, index}

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
            q.push({s[i], i});

            // Remove characters from the front that are no longer unique
            while (!q.empty() && freq[q.front().first] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front().second;
    
    }
};