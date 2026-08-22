class Solution {
public:
    void updateTree(int segIdx , int l , int r , int rank , vector<int>& segTree){
        if(l == r){
            segTree[segIdx]++;
            return;
        }
        int mid = (l+r)/2;
        if(rank <= mid) updateTree(2*segIdx+1 , l , mid , rank , segTree);
        else updateTree(2*segIdx+2 , mid+1 , r , rank , segTree);
        segTree[segIdx] = segTree[2*segIdx+1] + segTree[2*segIdx+2];
    }
    int query(int segIdx , int l , int r , int rank , vector<int>& segTree){
        if(rank >= r) return 0;
        if(rank < l) return segTree[segIdx];
        int mid = (l+r)/2;
        return query(2*segIdx+1,l,mid,rank,segTree)+query(2*segIdx+2,mid+1,r,rank,segTree);
    }
    vector<int> resultArray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());
        vector<int> rank;
        rank.push_back(sorted[0]);
        for(int i = 1 ; i<sorted.size() ; i++){
            if(sorted[i] != sorted[i-1]) rank.push_back(sorted[i]);
        }
        unordered_map<int,int> mpp;
        for(int i = 0 ; i<rank.size() ; i++) mpp[rank[i]] = i+1;
        vector<int> compressed(nums.size());
        for(int i = 0 ; i<nums.size() ; i++) compressed[i] = mpp[nums[i]];
        vector<int> arr1 , arr2 , segTree1(4*rank.size() , 0) , segTree2(4*rank.size() , 0);
        arr1.push_back(compressed[0]);
        updateTree(0,1,rank.size(),compressed[0],segTree1);
        arr2.push_back(compressed[1]);
        updateTree(0,1,rank.size(),compressed[1],segTree2);
        for(int i = 2 ; i<compressed.size();i++){
            int count1 = query(0,1,rank.size(),compressed[i],segTree1);
            int count2 = query(0,1,rank.size(),compressed[i],segTree2);
            if(count1 > count2 || ((count1 == count2) && (arr1.size() <= arr2.size()))){
                arr1.push_back(compressed[i]);
                updateTree(0,1,rank.size(),compressed[i],segTree1);
            }
            else{
                arr2.push_back(compressed[i]);
                updateTree(0,1,rank.size(),compressed[i],segTree2);
            }
        }
        for(int i = 0 ; i<arr2.size() ; i++) arr1.push_back(arr2[i]);
        for(int i = 0 ; i<arr1.size() ; i++) arr1[i] = rank[arr1[i]-1];
        return arr1;
    }
};