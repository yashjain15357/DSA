class Solution {
public:
    int compress(vector<char>& chars) {
        stack<pair<char , int>> st;
        char temp_ch = chars[chars.size()-1 ];
        int count = 0;
        for(int i = chars.size()-1 ; i>=0 ; i--){
            if(temp_ch!=chars[i]){
                st.push({temp_ch , count});
                count = 0;
                temp_ch = chars[i];

            }
            count++;
        }
        st.push({temp_ch , count});
        chars.clear();
        while(!st.empty()){
            auto pr = st.top();
            if(pr.second>1){
                chars.push_back(pr.first);
                std :: string freq = std::to_string(pr.second);
                for(char i : freq){
                    chars.push_back(i);
                }
            }
            else{
                chars.push_back(pr.first);
            }
            st.pop();

        }
        return chars.size();
        
        
    }
};