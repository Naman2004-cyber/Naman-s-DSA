class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> freq(1000 , 0);
        for(int i = 0 ; i<answers.size() ; i++) freq[answers[i]]++;
        int ans = 0;
        for(int i = 0 ; i<1000 ; i++){
            if(freq[i] == 0) continue;
            int type = i+1 , num = freq[i];
            ans+=((num/type) * type);
            if(num%type != 0) ans+=type;
        }
        return ans;
    }
};