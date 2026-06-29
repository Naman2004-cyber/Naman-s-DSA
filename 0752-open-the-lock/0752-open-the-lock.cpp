class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        for(int i = 0 ; i<deadends.size() ; i++)
        {
            if(deadends[i] == "0000") return -1;
            st.insert(deadends[i]);
        }
        queue<string> qt;
        qt.push("0000");
        st.insert("0000");
        int moves = 0;
        while(!qt.empty())
        {
            int n = qt.size();
            for(int i = 0 ; i<n ; i++)
            {
                string use = qt.front();
                qt.pop();
                if(use == target) return moves;
                for(int j = 0 ; j<4 ; j++)
                {
                    char ori = use[j];
                    if(use[j] == '0')
                    {
                        use[j] = '9';
                        if(st.find(use) == st.end()) 
                        {
                            qt.push(use);
                            st.insert(use);
                        }
                        use[j] = ori;
                        use[j]++;
                        if(st.find(use) == st.end()) 
                        {
                            qt.push(use);
                            st.insert(use);
                        }
                        use[j] = ori;
                    }
                    else if(use[j] == '9')
                    {
                        use[j] = '0';
                        if(st.find(use) == st.end()) 
                        {
                            qt.push(use);
                            st.insert(use);
                        }
                        use[j] = ori;
                        use[j]--;
                        if(st.find(use) == st.end()) 
                        {
                            qt.push(use);
                            st.insert(use);
                        }
                        use[j] = ori;
                    }
                    else
                    {
                        use[j]++;
                        if(st.find(use) == st.end()) 
                        {
                            qt.push(use);
                            st.insert(use);
                        }
                        use[j] = ori;
                        use[j]--;
                        if(st.find(use) == st.end()) 
                        {
                            qt.push(use);
                            st.insert(use);
                        }
                        use[j] = ori;
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};