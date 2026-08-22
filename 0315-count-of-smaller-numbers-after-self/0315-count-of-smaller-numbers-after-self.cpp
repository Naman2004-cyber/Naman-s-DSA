class Solution {
public:
    void updateTree(int segIdx , int l , int r , int rank , vector<int> &segTree){
        if(l == r){
            segTree[segIdx]++;
            return;
        }
        int mid = (l+r)/2;
        if(rank <= mid) updateTree(2*segIdx+1 , l , mid , rank , segTree);
        else updateTree(2*segIdx+2 , mid+1 , r , rank , segTree);
        segTree[segIdx] = segTree[2*segIdx+1] + segTree[2*segIdx+2];
    }
    int query(int segIdx , int l , int r , int rank , vector<int> &segTree){
        if(l >= rank) return 0;
        if(r < rank) return segTree[segIdx];
        int mid = (l+r)/2;
        return query(2*segIdx+1,l,mid,rank,segTree) + query(2*segIdx+2,mid+1,r,rank,segTree);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());
        vector<int> rank;
        rank.push_back(sorted[0]);
        for(int i = 1 ; i<sorted.size() ; i++) if(sorted[i] != sorted[i-1]) rank.push_back(sorted[i]);
        unordered_map<int,int> mpp;
        for(int i = 0 ; i<rank.size() ; i++) mpp[rank[i]] = i+1;
        vector<int> compressed(nums.size());
        for(int i = 0 ; i<compressed.size() ; i++) compressed[i] = mpp[nums[i]];
        vector<int> ans(nums.size());
        vector<int> segTree(4*rank.size());
        for(int i = ans.size()-1 ; i>=0 ; i--){
            int smaller = query(0,1,rank.size(),compressed[i],segTree);
            ans[i] = smaller;
            updateTree(0,1,rank.size(),compressed[i],segTree);
        }
        return ans;
    }
};