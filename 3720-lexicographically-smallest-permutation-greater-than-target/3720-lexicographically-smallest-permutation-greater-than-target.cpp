class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26 , 0);
        for(int i = 0 ; i<s.size() ; i++) freq[s[i]-'a']++;
        string ans = "";
        int placed = 0;
        for(int i = 0 ; i<target.size() ; i++){
            char ch = target[i];
            if(placed == 0){
                if(freq[target[i]-'a'] == 0){
                    int flag = 0;
                    for(int j = (ch-'a')+1 ; j<26 ; j++){
                        if(freq[j] > 0){
                            char use = 'a' + j;
                            ans+=use;
                            freq[j]--;
                            flag = 1;
                            if(use > target[i]) placed = 1;
                            break;
                        }
                    }
                    if(flag == 0) return "";
                }
                else{
                    string use = "";
                    for(int j = 25 ; j>=0 ; j--){
                        if(j == target[i]-'a'){
                            for(int k = 0 ; k<(freq[j]-1) ; k++){
                                use+=(j+'a');
                            }
                        }
                        else{
                            for(int k = 0 ; k<freq[j] ; k++){
                                use+=(j+'a');
                            }
                        }
                    }
                    string leftTarget = target.substr(i+1);
                    if(use > leftTarget){
                        ans+=target[i];
                        freq[target[i]-'a']--;
                    }
                    else{
                         int flag = 0;
                        for(int j = (ch-'a')+1 ; j<26 ; j++){
                            if(freq[j] > 0){
                                char use = 'a' + j;
                                ans+=use;
                                freq[j]--;
                                flag = 1;
                                if(use > target[i]) placed = 1;
                                break;
                            }
                        }
                        if(flag == 0) return "";
                    }
                }
            }
            else{
                for(int j = 0 ; j<26 ; j++){
                    if(freq[j] > 0){
                        char use = 'a' + j;
                        ans+=use;
                        freq[j]--;
                        break;
                    }
                }
            }
        }
        if(ans <= target) return "";
        return ans;
    }
};