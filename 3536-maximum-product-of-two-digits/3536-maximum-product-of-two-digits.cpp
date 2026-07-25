class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        sort(str.begin() , str.end());
        cout << str;
        int last = str[str.size()-1]-'0';
        int secondLast = str[str.size()-2]-'0';
        int ans = last * secondLast;
        return ans;
    }
};