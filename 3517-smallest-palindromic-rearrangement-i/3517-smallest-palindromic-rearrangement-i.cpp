class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> chars(26 , 0);
        for(int i = 0 ; i<s.size() ; i++){
            chars[s[i]-'a']++;
        }
        string extra = "";
        string first = "";
        for(int i = 0 ; i<26 ; i++){
            if(chars[i] == 0) continue;
            if(chars[i]%2 != 0) extra = i + 'a';
            int times = chars[i]/2;
            for(int j = 0 ; j<times ; j++){
                first+=(i+'a');
            }
        }
        string finalans = "";
        finalans+=first;
        finalans+=extra;
        reverse(first.begin() , first.end());
        finalans+=first;
        return finalans;
    }
};