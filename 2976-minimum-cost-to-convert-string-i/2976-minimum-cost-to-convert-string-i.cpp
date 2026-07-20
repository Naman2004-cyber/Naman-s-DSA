class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> distance{26 , vector<long long>(26 , LLONG_MAX)};
        for(int i = 0 ; i<original.size() ; i++){
            distance[original[i]-'a'][changed[i]-'a'] = min(distance[original[i]-'a'][changed[i]-'a'] , (long long)cost[i]);
        }
        for(int i = 0 ; i<26 ; i++) distance[i][i] = 0;
        for(int k = 0 ; k<26 ; k++){
            for(int i = 0 ; i<26 ; i++){
                for(int j = 0 ; j<26 ; j++){
                    if(distance[i][k] != LLONG_MAX && distance[k][j] != LLONG_MAX){
                        distance[i][j] = min(distance[i][j] , distance[i][k]+distance[k][j]);
                    }
                }
            }
        }
        long long finalans = 0;
        for(int i = 0 ; i<source.size() ; i++){
            if(source[i] != target[i]){
                long long ans = distance[source[i]-'a'][target[i]-'a'];
                if(ans == LLONG_MAX) return -1;
                finalans+= distance[source[i]-'a'][target[i]-'a'];
            }
        }
        return finalans;
    }
};