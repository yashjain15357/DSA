class Solution {
public:
bool checkPlaindrom(string s){
    int i =0;
    int j = s.size()-1;
    while(j>i){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
    void fun(vector<vector<string>> &ans , vector<string> &curr , int indx , string &s){
        if(indx >= s.size()){
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int i = indx ; i<s.size() ; ++i){
            temp+=s[i];
            if(checkPlaindrom(temp)){
                curr.push_back(temp);
                fun(ans, curr , i+1 , s);
                curr.pop_back();
            }
        }
        


    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        int indx =0;
        fun(ans,curr , indx ,s);
        return ans;
        
        
    }
};