class Solution {
public:
    void buildTree(int segIdx , int l , int r , vector<int> &segTree , vector<int>& heights){
        if(l == r){
            segTree[segIdx] = l;
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*segIdx+1 , l , mid , segTree , heights);
        buildTree(2*segIdx+2 , mid+1 , r , segTree , heights);
        if(heights[segTree[2*segIdx+1]] >= heights[segTree[2*segIdx+2]]){
            segTree[segIdx] = segTree[2*segIdx+1];
        }
        else segTree[segIdx] = segTree[2*segIdx+2];
    }
    int findFirstMax(int segIdx , int l , int r , int start , int end , int target , vector<int>& segTree , vector<int> &heights){
        if (l > end || r < start) return -1;
        if(heights[segTree[segIdx]] <= target) return -1;
        if(l == r) return l;
        int mid = (l+r)/2;
        int left = findFirstMax(2*segIdx+1 , l , mid , start , end , target , segTree , heights);
        if(left != -1) return left;
        return findFirstMax(2*segIdx+2 , mid+1 , r , start , end , target , segTree , heights);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segTree(4*n);
        buildTree(0 , 0 , n-1 , segTree , heights);
        vector<int> ans;
        for(int i = 0 ; i<queries.size() ; i++){
            int min_idx = min(queries[i][0] , queries[i][1]);
            int max_idx = max(queries[i][0] , queries[i][1]);
            if(min_idx == max_idx){
                ans.push_back(min_idx);
                continue;
            }
            else if(heights[max_idx] > heights[min_idx]){
                ans.push_back(max_idx);
                continue;
            }
            int start = max_idx+1;
            int end = n-1;
            int target = max(heights[max_idx] , heights[min_idx]);
            int use = findFirstMax(0 , 0 , n-1 , start , end , target , segTree , heights);
            ans.push_back(use);
        }
        return ans;
    }
};