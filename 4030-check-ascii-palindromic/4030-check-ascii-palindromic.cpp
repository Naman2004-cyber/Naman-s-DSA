class Solution {
public:
    bool isPalindromic(string s) {
        string str = "";
        for(int i = 0 ; i<s.size() ; i++){
            int num = s[i];
            string curr = "";
            while(num != 0){
                int a = num%2;
                char ch = a + '0';
                curr = ch + curr;
                num = num/2;
            }
            while(curr.size() < 8){
                curr = '0' + curr;
            }
            str+=curr;
        }
        int l = 0;
        int r = str.size()-1;
        while(l <= r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};