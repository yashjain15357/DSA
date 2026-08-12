// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int m = s.length();
//         int n = t.length();
//         vector<int>ch_freq(256 , 0);
//         int l=0;
//         int r =0;
//         int min_len = INT_MAX;
//         int start_index = 0;
//         int count = 0;


//         for(char ch : t){
//             ch_freq[ch]++;
//         }

//         while(r<m){
//             char ch = s[r++];

//             if(ch_freq[ch]-- > 0){
//                 count++;
//             }

//             while(count==n){
//                 char lch = s[l++];
//                 if (r - l < min_len) {
//                     start_index = l;
//                     min_len = r - l;
//                 }

//                 if (ch_freq[lch]++ == 0) {
//                     count--;
//                 }
//             }
//         }
//         return min_len == INT_MAX ? "" : s.substr(start_index, min_len);

        
//     }
// };
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        /// UPVOTE !
        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};