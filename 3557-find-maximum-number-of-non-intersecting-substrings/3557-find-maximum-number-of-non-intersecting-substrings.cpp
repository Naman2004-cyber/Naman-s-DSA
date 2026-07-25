class Solution {
public:
    int maxSubstrings(string word) {
        unordered_map<char , int> mpp;
        int count = 0;
        for(int i = 0 ; i<word.size() ; i++){
            if(mpp.find(word[i]) != mpp.end()){
                if(i - mpp[word[i]] >= 3){
                    mpp.clear();
                    count++;
                }
            }
            else{
                mpp[word[i]] = i;
            }
        }
        return count;
    }
};