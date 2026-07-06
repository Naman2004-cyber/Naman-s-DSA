class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string , string> mpp;
        for(int i = 0 ; i<messages.size() ; i++)
        {
            if(mpp.find(senders[i]) == mpp.end())
            {
                mpp[senders[i]] = messages[i];
            }
            else
            {
                mpp[senders[i]]+=" ";
                mpp[senders[i]]+=messages[i];
            }
        }
        string ans = "";
        int maxi = 0;
        for(auto &it : mpp)
        {
            string str = it.second;
            int count = 0;
            stringstream ss(str);
            string word;
            while(ss >> word)
            {
                count++;
            }
            if(count > maxi)
            {
                maxi = count;
                ans = it.first;
            }
            else if(count == maxi && it.first > ans)
            {
                ans = it.first;
            }
        }
        return ans;
    }
};