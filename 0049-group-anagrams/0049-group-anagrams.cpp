class Solution {
public:
bool ngram(string word1 , string word2){
    if(word1.length()== word2.length()){
        vector<int>chars(26,0);
        for(char ch : word1){
            chars[ch-'a']++;
        }

        for(char ch : word2){
            int ch_index = ch-'a';
            if(chars[ch_index]>0){
                chars[ch_index]--;
            }
            else{
                return false;
            }
        }
        return true;

    }
    return false;

}
int str_sum(string word){
    int sum = 0;
    for(char ch : word){
        sum+=(ch-'a');
    }
    return sum;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // big O n^3 time complexity
        // vector<vector<string>> strings ;
        
        // while(!strs.empty()){
        //     vector<string> temp;
        //     string temp_string = strs[0];
        //     for(int i  = 0 ; i<strs.size() ; i++){
        //         bool val = ngram(temp_string , strs[i]);
        //         if(val){
        //             temp.push_back(strs[i]);
        //             strs.erase(strs.begin() + i);
        //             i--;
        //         }
        //     }
        //     strings.push_back(temp);
        //     temp.clear();
        //     }

        //   return strings; 


// wrong approach
        // vector<vector<string>> strings;
        // unordered_map<int , vector<string>> mp;
        // for(string word : strs){
        //     int sum = str_sum(word);
        //     mp[sum].push_back(word);
        // }

        // for(auto& pair : mp){
        //     strings.push_back(pair.second);
        // }
        // return strings;


        unordered_map<string, vector<string>> mp;
        
        for (const string& word : strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end()); // Anagrams share the same sorted key
            mp[sorted_word].push_back(word);
        }
        
        vector<vector<string>> result;
        for (auto& pair : mp) {
            result.push_back(move(pair.second));
        }
        
        return result;


        }
        
    }
;