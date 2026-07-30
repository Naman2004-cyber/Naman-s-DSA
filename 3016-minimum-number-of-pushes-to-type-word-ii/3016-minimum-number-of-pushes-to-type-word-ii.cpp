class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26 , 0);
        for(int i = 0 ; i<word.size() ; i++) arr[word[i]-'a']++;
        sort(arr.begin() , arr.end());
        // for(int i = 0 ; i<arr.size(); i++) cout << arr[i] << " ";
        int ans = 0 , mul = 1 , count = 0;
        for(int i = 25 ; i>=0 ; i--){
            if(arr[i] == 0) break;
            ans = ans + mul*arr[i];
            count++;
            if(count == 8){
                count = 0;
                mul++;
            }
        }
        return ans;
    }
};