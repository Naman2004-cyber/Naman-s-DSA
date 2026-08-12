class Solution {
public:
    void update(int segIdx , int l , int r , int start , int end , vector<int> &segTree , vector<int> &lazy){
        if(lazy[segIdx] != 0){
            segTree[segIdx] = (r-l+1) - segTree[segIdx];
            if(l < r){
                lazy[2*segIdx+1]^=1;
                lazy[2*segIdx+2]^=1;
            }
            lazy[segIdx] = 0;
        }
        if(l > end || r < start) return;
        if(l >= start && r <= end){
            segTree[segIdx] = (r-l+1) - segTree[segIdx];
            if(l < r){
                lazy[2*segIdx+1]^=1;
                lazy[2*segIdx+2]^=1;
            }
            return;
        }
        int mid = (l+r)/2;
        update(2*segIdx+1 , l , mid , start , end , segTree , lazy);
        update(2*segIdx+2 , mid+1 , r , start , end , segTree , lazy);
        segTree[segIdx] = segTree[2*segIdx+1] + segTree[2*segIdx+2];
    }
    void buildTree(int segIdx , int l , int r , vector<int> &nums , vector<int> &segTree){
        if(l == r){
            segTree[segIdx] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*segIdx+1 , l , mid , nums , segTree);
        buildTree(2*segIdx+2 , mid+1 , r , nums , segTree);
        segTree[segIdx] = segTree[2*segIdx+1] + segTree[2*segIdx+2];
    }
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<int> segTree(4*n);
        vector<int> lazy(4*n , 0);
        buildTree(0 , 0 , n-1 , nums1 , segTree);
        long long sum = 0;
        for(int i = 0 ; i<nums2.size() ; i++) sum+=nums2[i];
        vector<long long> ans;
        for(auto &q : queries){
            int type = q[0];
            int l = q[1];
            int r = q[2];
            if(type == 1) update(0 , 0 , n-1 , l , r , segTree , lazy);
            else if(type == 2){
                long long p = q[1];
                long long ones = segTree[0];
                sum+=(p*ones);
            }
            else{
                ans.push_back(sum);
            }
        }
        return ans;
    }
};