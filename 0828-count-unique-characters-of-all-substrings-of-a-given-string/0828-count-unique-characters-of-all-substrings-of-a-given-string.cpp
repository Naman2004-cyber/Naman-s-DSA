// the brute force that we can do in this question is going through each and every substring and checking in it , how many unique character are there , but it can result in tle as we are generating all the substrings ,,,, rather than that what we can do is that we can check for each character that in how many substrings it is coming as a unique character and we can do it for all the characters and the sum of that will be the answer 

// to find this for a particluar character ,,,, we have to know the index where the same character had come just before the current index and we have to knwo the index where the same character has come just after the current index ,,,, because the substrings forming within these indices (exclusive) will be the one having this character as the unique character 

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> mpp1(26 , -1);
        vector<int> justBefore(s.size() , -1);
        for(int i = 0 ;  i<s.size() ; i++)
        {
            justBefore[i] = mpp1[s[i]-'A'];
            mpp1[s[i]-'A'] = i;
        }
        vector<int> mpp2(26 , -1);
        vector<int> justAfter(s.size() , -1);
        for(int i = s.size()-1 ; i>=0 ; i--)
        {
            justAfter[i] = mpp2[s[i]-'A'];
            mpp2[s[i]-'A'] = i;
        } 
        int ans = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            int first = justBefore[i] == -1 ? i+1 : i - justBefore[i];
            int second = justAfter[i] == -1 ? s.size()-i : justAfter[i] - i;
            ans = ans + (first * second);
        }
        return ans;

    }
};