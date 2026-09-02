class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> finalAns;
        for(int i = 0 ; i<nums.size() ; i++){
            int num = nums[i];
            string ans = "";
            while(num > 0){
                int index = 0;
                int sum = 1;
                while(sum <= num){
                    sum*=2;
                    index++;
                }
                num-=(sum/2);
                if(index == 27){
                    ans+="zz";
                }
                else{
                    char ch = 'a' + index - 1;
                    ans+=ch;
                }
            }
            finalAns.push_back(ans);
        }
        return finalAns;
    }
};