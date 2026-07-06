class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> final;
        sort(intervals.begin() , intervals.end());
        for(int i = 0 ; i<intervals.size() ; i++)
        {
            if(final.empty())
            {
                final.push_back(intervals[i]);
            }
            else
            {
                if(intervals[i][0] <= final.back()[0] && final.back()[1] <= intervals[i][1])
                {
                    final.pop_back();
                }
                else if(intervals[i][0] >= final.back()[0] && final.back()[1] >= intervals[i][1])
                {
                    continue;
                }
                final.push_back(intervals[i]);
            }
        }
        return final.size();
    }
};