class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int , int>> ones;
        int start = -1;
        int end = -1;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '1'){
                if(start == -1){
                    start = i;
                    end = i;
                }
                else{
                    end = i;
                }
            }
            else{
                if(start != -1 && end != -1) ones.push_back({start , end});
                start = -1;
                end = -1;
            }
        }
        if(start != -1 && end != -1) ones.push_back({start , end});

        if(ones.size() == 0) return 0;
        // for(auto& it : ones){
        //     cout << it.first << it.second << endl;
        // }

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

        vector<int> left1(s.size() , 0);
        int count1left = 0;
        for(int i = 0 ; i<s.size() ; i++){
            left1[i] = count1left;
            if(s[i] == '1') count1left++;
        }

        vector<int> right1(s.size() , 0);
        int count1right = 0;
        for(int i = s.size()-1 ; i>=0 ; i--){
            right1[i] = count1right;
            if(s[i] == '1') count1right++;
        }
        // for(int i = 0 ; i<left1.size() ; i++) cout << right1[i] << " ";
        int maxi = 1;
        for(int i = 0 ; i<ones.size() ; i++){
            int start = ones[i].first;
            int end = ones[i].second;
            int onesLeft = mppLeft[start];
            int onesRight = mppRight[end];
            if(onesLeft > 0 && onesRight > 0){
                start = start - onesLeft;
                end = end + onesRight;
            }
            int outOfLeft = left1[start];
            int outOfRight = right1[end];
            maxi = max(maxi , end-start+1 + outOfRight + outOfLeft);
        }
        return maxi;
    }
};