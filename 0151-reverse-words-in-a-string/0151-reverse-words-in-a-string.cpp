class Solution {
public:
    
    string reverseWords(string s) {
        // string a ;
        // for(int i=s.length()-1 ; i>=0 ; i--){

        //     if((s[i]==' ' && i!=s.length()) || i==0){
        //         int j=i+1;
        //         if(i==0 && s[i]!=' '){
        //             j=i;
        //         }
        //         int check =0;
        //         while(s[j]!=' '&& j<s.length()){
        //             a.push_back(s[j]);
        //             check =1;
        //             j++;
        //         }
        //         if(check==1){
        //             a.push_back(' ');
        //             check=0;
        //         }
        //         if(i==0){
        //             a.pop_back();
        //         }

                
        //     }
        // }
        // s=a;
        // return s;
// Step 1: Reverse the whole string
        reverse(s.begin(), s.end());

        int n = s.length();
        int idx = 0; // Pointer for the cleaned string write-position

        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // Add a space between words in the new layout
                if (idx != 0) s[idx++] = ' ';

                int end = start;
                while (end < n && s[end] != ' ') {
                    s[idx++] = s[end++];
                }

                // Reverse the word back to correct order
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                start = end; // Move main loop index forward
            }
        }

        // Trim any trailing unused characters left over
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};