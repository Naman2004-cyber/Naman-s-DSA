class Solution {
public:
    bool doit(int idx , string &ans , string &s , string &target , vector<int> &freq , int greater){
        if(idx == s.size()){
            if(greater == 1){
                return true;
            }
            return false;
        }
        for(char ch = 'a' ; ch <= 'z' ; ch++){
            if(freq[ch-'a'] == 0) continue;
            if(greater == 0 && (ch < target[idx])) continue;
            ans+=ch;
            freq[ch-'a']--;
            int newgreater = greater || (ch > target[idx]) ? 1 : 0;
            if(doit(idx+1 , ans , s , target , freq , newgreater)) return true;
            ans.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        string ans = "";
        vector<int> freq(26 , 0);
        for(int i = 0 ; i<s.size() ; i++) freq[s[i]-'a']++;
        bool get = doit(0 , ans , s , target , freq , 0);
        if(get ==  false) return "";
        return ans;
    }
};