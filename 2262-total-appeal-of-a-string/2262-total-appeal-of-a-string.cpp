// now we can do this question by just taking all the substrings and counting the number of distinct character in this ,,, means only the first occurence of all the characters in them 

// but rather than doing we can find for all characters that in how many substrings they are acting as the first occurence of that character 

// there can be three ways :
// 1) All the substrings starting from this character will be the one in which this acts as the distinct character as it is definately  the first occurence of this character in the string
// 2) All the substrings in which this the last character ,,, and there is no other occurence of this character in the substring ,,,
// 3) The substrings in which this character is somewhere in the middle , but it is the first occurence of that character in the string 
class Solution {
public:
    long long appealSum(string s) {
        vector<int> mpp1(26 , -1);
        vector<int> justBefore(s.size() , -1);
        vector<int> firstOccu(26 , -1);
        for(int i = 0 ;  i<s.size() ; i++)
        {
            if(firstOccu[s[i]-'a'] == -1) firstOccu[s[i]-'a'] = i;
            justBefore[i] = mpp1[s[i]-'a'];
            mpp1[s[i]-'a'] = i;
        }
        long long ans = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            ans+=(s.size()-i);
        }
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(justBefore[i] == -1)
            {
                ans+=i;
            }
            else
            {
                ans+=(i-justBefore[i]-1);
            }
        }
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(justBefore[i] == -1)
            {
                ans = ans + (i*(s.size()-i-1));
            }
            else 
            {
                ans = ans + ((i-justBefore[i]-1)*(s.size()-i-1));
            }
        }
        return ans;
    }
};