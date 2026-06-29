class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin() , occupiedIntervals.end());
        vector<vector<int>> merged;
        for(int i = 0 ; i<occupiedIntervals.size() ; i++)
        {
            if(merged.empty())
            {
                merged.push_back(occupiedIntervals[i]);
            }
            else 
            {
                if(merged.back()[1]+1 >= occupiedIntervals[i][0])
                {
                    merged.back()[1] = max(merged.back()[1] , occupiedIntervals[i][1]);
                }
                else
                {
                    merged.push_back(occupiedIntervals[i]);
                }
            }
        }
        vector<vector<int>> finalmerged;
        for(int i = 0 ; i<merged.size() ; i++)
        {
            if((freeEnd < merged[i][0]) || (freeStart > merged[i][1]))
            {
                finalmerged.push_back(merged[i]);
            }
            else if((freeStart <= merged[i][0]) && (freeEnd >= merged[i][0] && freeEnd < merged[i][1]))
            {
                finalmerged.push_back({freeEnd+1,merged[i][1]});
            }
            else if((freeStart > merged[i][0] && freeStart <= merged[i][1]) && (freeEnd >= merged[i][1]))
            {
                finalmerged.push_back({merged[i][0] , freeStart-1});
            }
            else if((freeStart > merged[i][0] && freeStart < merged[i][1]) && (freeEnd > merged[i][0] && freeEnd < merged[i][1]))
            {
                finalmerged.push_back({merged[i][0] , freeStart-1});
                finalmerged.push_back({ freeEnd+1 , merged[i][1]});
            }
        }
        return finalmerged;
    }
};