class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }

        vector<int>letter(26 , 0);

        for(char ch : s){
            letter[ch-'a']++;
        }

        for(char ch : t){
            if(letter[ch-'a']<=0){
                return false;
            }
            letter[ch - 'a']--;
        }
        return true;
        

        
        
    }
};