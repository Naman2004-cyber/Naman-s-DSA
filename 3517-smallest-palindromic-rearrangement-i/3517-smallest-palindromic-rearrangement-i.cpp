class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> chars(26 , 0);
        for(int i = 0 ; i<s.size() ; i++){
            chars[s[i]-'a']++;
        }
        sort(s.begin() , s.end());
        string first = "";
        string second = "";
        string extra = "";
        for(int i = 0 ; i<26 ; i++){
            if(chars[i]%2 != 0){
                extra = i+'a';
                chars[i]--;
                break;
            }
        }
        for(int i = 0 ; i<s.size() ; i++){
            if(chars[s[i]-'a'] == 0) continue;
            if(chars[s[i]-'a']%2 == 0) first+=s[i];
            else second+=s[i];
            chars[s[i]-'a']--;
        }
        reverse(second.begin() , second.end());
        string finalans = "";
        finalans+=first;
        finalans+=extra;
        finalans+=second;
        return finalans;
    }
};