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
        int leftMaxIdx = segTree[2*segIdx+1];
        int rightMaxIdx = segTree[2*segIdx+2];
        segTree[segIdx] = heights[leftMaxIdx] >= heights[rightMaxIdx] ? leftMaxIdx : rightMaxIdx;
    }
    int rmiq(int segIdx , int l , int r , int start , int end , vector<int> &segTree , vector<int> &heights){
        if(l > end || r < start) return -1;
        if(l >=  start && r <= end) return segTree[segIdx];
        int mid = (l+r)/2;
        int left = rmiq(2*segIdx+1 , l , mid , start , end , segTree , heights);
        int right = rmiq(2*segIdx+2 , mid+1 , r , start , end , segTree , heights);
        if(left == -1) return right;
        if(right == -1) return left;
        if(heights[left] >= heights[right]) return left;
        return right;
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
            int low = max_idx+1;
            int high = n-1;
            int use = INT_MAX;
            while(low <= high){
                int mid = low + ((high-low)/2);
                int idx = rmiq(0 , 0 , n-1 , low , mid , segTree , heights);
                if(heights[idx] > max(heights[min_idx] , heights[max_idx])){
                    use = idx;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            if(use == INT_MAX) ans.push_back(-1);
            else ans.push_back(use);
        }
        return ans;
    }
};