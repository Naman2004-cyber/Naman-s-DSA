class Solution {
public:
    int maximumGap(string skill, string station) {
        int i = 0;
        int j = 0;
        vector<int> use1;
        while(i < skill.size()-1 && j < station.size()){
            if(skill[i] == station[j]){
                use1.push_back(j);
                i++;
            }
            j++;
        }
        for(int i = station.size()-1 ; i>=0 ; i--){
            if(station[i] == skill[skill.size()-1]){
                use1.push_back(i);
                break;
            }
        }

        int i1 = skill.size()-1;
        int j1 = station.size()-1;
        int index = skill.size()-1;
        vector<int> use2(skill.size());
        while(i1 >=1 && j1 >=0){
            if(skill[i1] == station[j1]){
                use2[index] = j1;
                index--;
                i1--;
            }
            j1--;
        }
        for(int i = 0 ; i<station.size() ; i++){
            if(station[i] == skill[0]){
                use2[0] = i;
                break;
            }
        }

        int maxi = 0;
        for(int i = 0 ; i<skill.size()-1 ; i++){
            int first = min(use1[i] , use2[i]);
            int second = max(use1[i+1] , use2[i+1]);
            maxi = max(maxi , second-first);
        }
        return maxi;
    }
};