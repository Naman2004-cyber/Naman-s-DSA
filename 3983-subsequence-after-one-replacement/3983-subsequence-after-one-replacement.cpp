class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i=0,j=0;
        int n=s.size(),m=t.size();
        while(i<n&&j<m){
            if(t[j]!=s[i])++j;
            else{
                if(t[j]==s[i])++i,++j;
            }
        }
        if(i==n)return true;
        int lm=i-1;
        cout<<lm;
        if(lm==0&&j==m){
            int lm2=-1;
            for(char c='a';c<='z';++c){
                string s1=s;
                s1[lm2+1]=c;
                int i=0,j=0;
                while(i<n&&j<m){
                    if(t[j]!=s1[i])++j;
                    else ++i,++j;
                }
                if(i==n)return true;
            }
            
        }
        for(char c='a';c<='z';++c){
            string s1=s;
            s1[lm+1]=c;
            int i=0,j=0;
            while(i<n&&j<m){
                if(t[j]!=s1[i])++j;
                else ++i,++j;
            }
            if(i==n)return true;
        }
        return false;
    }
};