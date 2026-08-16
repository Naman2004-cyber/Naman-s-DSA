class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<int> qt;
        qt.push(x);
        int level = 0;
        unordered_set<int> vis;
        vis.insert(x);
        while(!qt.empty()){
            int n = qt.size();
            for(int i = 0 ; i<n ; i++){
                int num = qt.front();
                qt.pop();
                if(num == y) return level;
                // 4 operations;
                int use1 = num/11;
                if(num%11 == 0 && vis.count(use1) == 0){
                    qt.push(num/11);
                    vis.insert(use1);
                }
                int use2 = num/5;
                if(num%5 == 0 && vis.count(use2) == 0){
                    qt.push(num/5);
                    vis.insert(use2);
                }
                int use3 = num-1;
                if(vis.count(use3) == 0) {
                    qt.push(num-1);
                    vis.insert(use3);
                }
                int use4 = num+1;
                if(vis.count(use4) == 0){
                    qt.push(num+1);
                    vis.insert(use4);
                }
            }
            level++;
        }
        return 0;
    }
};