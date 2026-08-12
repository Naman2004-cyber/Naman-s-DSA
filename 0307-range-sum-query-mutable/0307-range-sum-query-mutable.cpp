class NumArray {
public:
    vector<int> arr;
    vector<int> segTree;
    NumArray(vector<int>& nums) {
        arr = nums;
        int n = nums.size();
        segTree.resize(4*n);
        buildTree(0 , 0 , arr.size()-1);
    }
    void buildTree(int idx , int l , int r){
        if(l == r){
            segTree[idx] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*idx+1 , l , mid);
        buildTree(2*idx+2 , mid+1 , r);
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    void updateTree(int segIdx , int lSegRange , int rSegRange , int updateIdx , int updateVal){
        if(lSegRange == rSegRange){
            segTree[segIdx] = updateVal;
            return;
        }
        int mid = (lSegRange + rSegRange)/2;
        if(updateIdx <= mid){
            updateTree(2*segIdx+1 , lSegRange , mid , updateIdx , updateVal);
        }
        else{
            updateTree(2*segIdx+2 , mid+1 , rSegRange , updateIdx , updateVal);
        }
        segTree[segIdx] = segTree[2*segIdx+1] + segTree[2*segIdx+2];
    }
    int sumRangeFind(int segIdx , int l , int r , int start , int end){
        if(r < start || l > end) return 0;
        if(l >= start && r <= end) return segTree[segIdx];
        int mid = (l+r)/2;
        int left = sumRangeFind(2*segIdx+1 , l , mid , start , end);
        int right = sumRangeFind(2*segIdx+2 , mid+1 , r , start , end);
        return left + right;
    }
    void update(int index, int val) {
        updateTree(0 , 0 , arr.size()-1 , index , val);
    }
    int sumRange(int left, int right) {
        return sumRangeFind(0 , 0 , arr.size()-1 , left , right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */