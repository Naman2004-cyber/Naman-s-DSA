class Solution {
public:
    void doit(int idx , vector<int>& freq , int num , vector<int> &ans){
        if(idx >= 3){
            ans.push_back(num);
            num = 0;
            return;
        }
        for(int i = 0 ; i<=9 ; i++){
            if(idx == 0 && i != 0 && freq[i] != 0){
                num = num * 10 + i;
                freq[i]--;
                doit(idx+1 , freq , num , ans);
                num = num/10;
                freq[i]++;
            }
            else if(idx == 2 && i%2 == 0 && freq[i] != 0){
                num = num * 10 + i;
                freq[i]--;
                doit(idx+1 , freq , num , ans);
                num = num/10;
                freq[i]++;
            }
            else if(idx == 1 && freq[i] != 0){
                num = num * 10 + i;
                freq[i]--;
                doit(idx+1 , freq , num , ans);
                num = num/10;
                freq[i]++;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int num = 0;
        vector<int> ans;
        vector<int> freq(10 , 0);
        for(int i = 0 ; i<digits.size() ; i++) freq[digits[i]]++;
        doit(0 , freq , num , ans);
        return ans;
    }
};