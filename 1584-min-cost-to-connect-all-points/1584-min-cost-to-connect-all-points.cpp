class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<vector<int>> st;
        for(auto &it : points) st.insert(it);
        int sum = 0;
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;
        pq.push({0 , {points[0][0],points[0][1]}});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currdist = it.first;
            int currx = it.second.first;
            int curry = it.second.second;
            if(st.find({currx , curry}) == st.end()) continue;
            sum+=currdist;
            st.erase({currx , curry});
            for(auto &it : st)
            {
                int newdist = abs(it[0] - currx) + abs(it[1] - curry);
                pq.push({newdist , {it[0] , it[1]}});
            }
        }
        return sum;
    }
};