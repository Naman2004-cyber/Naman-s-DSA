class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int , int>> ones;
        int start = -1;
        int end = -1;
        int totalones = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '1'){
                if(start == -1){
                    start = i;
                    end = i;
                }
                else{
                    end = i;
                }
                totalones++;
            }
            else{
                if(start != -1 && end != -1) ones.push_back({start , end});
                start = -1;
                end = -1;
            }
        }
        if(start != -1 && end != -1) ones.push_back({start , end});
        if(ones.size() == 0) return 0;
        unordered_map<int , int> mppLeft;
        int count0left = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '1'){
                mppLeft[i] = count0left;
                count0left = 0;
            }
            else{
                count0left++;
            }
        }
        unordered_map<int , int> mppRight;
        int count0Right = 0;
        for(int i = s.size()-1 ; i>=0 ; i--){
            if(s[i] == '1'){
                mppRight[i] = count0Right;
                count0Right = 0;
            }
            else{
                count0Right++;
            }
        }
        int maxi = 1;
        for(int i = 0 ; i<ones.size() ; i++){
            int start = ones[i].first;
            int end = ones[i].second;
            int onesLeft = mppLeft[start];
            int onesRight = mppRight[end];
            int add = 0;
            if(onesLeft > 0 && onesRight > 0){
                add = onesLeft + onesRight;
            }
            maxi = max(maxi , add+totalones);
        }
        return maxi;
    }
};