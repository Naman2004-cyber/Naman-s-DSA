class Solution {
public:
    void updateTree(int segIdx , int l , int r , int rank , vector<int>& segTree){
        if(l  == r){
            segTree[segIdx]++;
            return;
        }
        int mid = (l+r)/2;
        if(rank <= mid) updateTree(2*segIdx+1 , l , mid , rank , segTree);
        else updateTree(2*segIdx+2 , mid+1 , r , rank , segTree);
        segTree[segIdx] = segTree[2*segIdx+1] + segTree[2*segIdx+2];
    }
    int greaterQuery(int segIdx , int l , int r , int rank , vector<int>& segTree){
        if(rank >= r) return 0;
        if(rank < l) return segTree[segIdx];
        int mid = (l+r)/2;
        return greaterQuery(2*segIdx+1,l,mid,rank,segTree)+greaterQuery(2*segIdx+2,mid+1,r,rank,segTree);
    }
    int smallerQuery(int segIdx , int l , int r , int rank , vector<int>& segTree){
        if(rank <= l) return 0;
        if(rank > r) return segTree[segIdx];
        int mid = (l+r)/2;
        return smallerQuery(2*segIdx+1,l,mid,rank,segTree)+smallerQuery(2*segIdx+2,mid+1,r,rank,segTree);
    }
    int mod = 1e9+7;
    int createSortedArray(vector<int>& instructions) {
        vector<int> sorted = instructions;
        sort(sorted.begin() , sorted.end());
        vector<int> rank;
        rank.push_back(sorted[0]);
        for(int i=1;i<sorted.size();i++) if(sorted[i]!=sorted[i-1]) rank.push_back(sorted[i]);
        unordered_map<int,int> mpp;
        for(int i = 0 ; i<rank.size() ; i++) mpp[rank[i]] = i+1;
        vector<int> compressed(instructions.size());
        for(int i = 0 ; i<compressed.size() ; i++) compressed[i] = mpp[instructions[i]];
        vector<int> segTree(4*rank.size(),0);
        int cost = 0;
        for(int i = 0 ; i<compressed.size() ; i++){
            int greater = greaterQuery(0,1,rank.size(),compressed[i],segTree);
            int smaller = smallerQuery(0,1,rank.size(),compressed[i],segTree);;
            cost = (cost + min(greater , smaller))%mod;
            updateTree(0,1,rank.size(),compressed[i],segTree);
        }
        return cost;
    }
};