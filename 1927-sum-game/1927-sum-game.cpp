class Solution {
public:
    bool sumGame(string num) {
        int countLeft = 0; 
        int countRight = 0;
        int half = num.size()/2;
        int leftSum = 0 , rightSum = 0;
        for(int i = 0 ; i<num.size() ; i++){
            if(i < half) {
                if(num[i] == '?') countLeft++;
                else leftSum+=(num[i]-'0');
            }
            else {
                if(num[i] == '?') countRight++;
                else rightSum+=(num[i]-'0');
            }
        }
        if(countLeft == 0 && countRight == 0){
            if(leftSum != rightSum) return true;
            return false;
        }
        int total = countLeft + countRight;
        int turn = 0; // 0 means turn of alice and 1 means turn of bob
        for(int i = 0 ; i<total ; i++){
            if(turn == 0){
                if(leftSum > rightSum){
                    if(countLeft > 0) {
                        leftSum+=9;
                        countLeft--;
                    }
                    else if(countRight > 0) {
                        int diff = leftSum - rightSum;
                        if(diff < 9){
                            rightSum+=9;
                        }
                        else rightSum+=0;
                        countRight--;
                    }
                }
                else if(rightSum > leftSum){
                    if(countRight > 0){
                        rightSum+=9;
                        countRight--;
                    }
                    else if(countLeft > 0){
                        int diff = rightSum - leftSum;
                        if(diff < 9){
                            leftSum+=9;
                        }
                        else leftSum+=0;
                        countLeft--;
                    }
                }
                else{
                    if(countLeft > 0){
                        leftSum+=9;
                        countLeft--;
                    }
                    else if(countRight > 0){
                        rightSum+=9;
                        countRight--;
                    }
                }
            }
            else{
                if(rightSum < leftSum){
                    int diff = leftSum - rightSum;
                    int valToAdd = diff > 9 ? 9 : diff;
                    if(countRight > 0){
                        rightSum+=valToAdd;
                        countRight--;
                    }
                    else if(countLeft > 0){
                        leftSum+=0;
                        countLeft--;
                    }
                }
                else if(leftSum < rightSum){
                    int diff = rightSum - leftSum;
                    int valToAdd = diff > 9 ? 9 : diff;
                    if(countLeft > 0){
                        leftSum+=valToAdd;
                        countLeft--;
                    }
                    else if(countRight > 0){
                        rightSum+=0;
                        countRight--;
                    }
                }
            }
            turn = turn == 0 ? 1 : 0;
        }
        if(leftSum == rightSum) return false;
        return true;
    }
};