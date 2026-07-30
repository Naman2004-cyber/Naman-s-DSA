class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastSeen(26 , 0);
        vector<int> ans;
        for(int i = 0 ; i<s.size() ; i++) lastSeen[s[i]-'a'] = i;
        int i = 0 , j = 0;
        int maxi = INT_MIN;
        while(i < s.size() && j < s.size()){
            maxi = max(lastSeen[s[j]-'a'] , maxi);
            if(lastSeen[s[j]-'a'] == j && lastSeen[s[j]-'a'] == maxi){
                ans.push_back(j-i+1);
                j++;
                i = j;
                maxi = INT_MIN;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};