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
    int freqQuery(int segIdx , int l , int r , int targetRank , vector<int>& segTree){
        if(targetRank >= r) return 0;
        if(targetRank < l) return segTree[segIdx];
        // if(l == r){
        //     return segTree[segIdx];
        // }
        int mid = (l+r)/2;
        int left = freqQuery(2*segIdx+1 , l , mid , targetRank , segTree);
        int right  = freqQuery(2*segIdx+2 , mid+1 , r , targetRank , segTree);
        return left+right;
    }
    vector<int> resultArray(vector<int>& nums) {
        unordered_map<int , int> mpp;
        vector<int> rank = nums;
        sort(rank.begin() , rank.end());
        int useRank = 1;
        for(int i= 0 ; i<rank.size() ; i++){
            if(mpp.find(rank[i]) == mpp.end()){
                mpp[rank[i]] = useRank;
                useRank++;
            }
        }
        unordered_map<int , int> rankMpp;
        for(int i = 0 ; i<nums.size() ; i++){
            rank[i] = mpp[nums[i]];
            rankMpp[rank[i]] = nums[i];
        }
        vector<int> segTree1(4*mpp.size());
        vector<int> arr1;
        arr1.push_back(rank[0]);
        updateTree(0 , 1 , mpp.size() , rank[0] , segTree1);
        vector<int> segTree2(4*mpp.size());
        vector<int> arr2;
        arr2.push_back(rank[1]);
        updateTree(0 , 1 , mpp.size() , rank[1] , segTree2);
        for(int i = 2 ; i<rank.size() ; i++){
            int countArr1 = freqQuery(0 , 1 , mpp.size() , rank[i] , segTree1);
            int countArr2 = freqQuery(0 , 1 , mpp.size() , rank[i] , segTree2);
            if(countArr1 > countArr2){
                arr1.push_back(rank[i]);
                updateTree(0 , 1 , mpp.size() , rank[i] , segTree1);
            }
            else if(countArr1 < countArr2){
                arr2.push_back(rank[i]);
                updateTree(0 , 1 , mpp.size() , rank[i] , segTree2);
            }
            else if(arr1.size() < arr2.size()){
                arr1.push_back(rank[i]);
                updateTree(0 , 1 , mpp.size() , rank[i] , segTree1);
            }
            else if(arr1.size() > arr2.size()){
                arr2.push_back(rank[i]);
                updateTree(0 , 1 , mpp.size() , rank[i] , segTree2);
            }
            else{
                arr1.push_back(rank[i]);
                updateTree(0 , 1 , mpp.size() , rank[i] , segTree1);
            }
        }
        for(int i = 0 ; i<arr2.size() ; i++) arr1.push_back(arr2[i]);
        for(int i = 0 ; i<arr1.size() ; i++) arr1[i] = rankMpp[arr1[i]];
        return arr1;
    }
};