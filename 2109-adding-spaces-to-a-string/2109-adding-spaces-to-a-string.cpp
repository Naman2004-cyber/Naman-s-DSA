class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        int j = 0;
        string ans = "";
        while(i < s.size()){
            if(j < spaces.size() && i == spaces[j]){
                ans+=" ";
                j++;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};