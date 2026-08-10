class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0.0;
        sort(prices.begin() , prices.end() , greater<int>());
        sort(discounts.begin() , discounts.end() , greater<int>());
        int d = 0;
        int p = 0;
        while(p < prices.size()){
            if(d < discounts.size()){
                ans = ans + (  (prices[p] * (100 - discounts[d])  )/100.0   );
                d++;
            }
            else{
                ans = ans + prices[p];
            }
            p++;
        }
        return ans;
    }
};