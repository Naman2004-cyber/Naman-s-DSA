class Solution {
public:
    int minimumPushes(string word) {
        int count = 0;
        int mul = 1;
        int total = word.size();
        while(total > 0){
            int use = min(8 , total);
            count = count + mul*use;
            mul++;
            total-=use;
        }
        return count;
    }
};