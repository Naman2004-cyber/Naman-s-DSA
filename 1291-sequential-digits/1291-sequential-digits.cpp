class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> numbers;
        vector<int> special;
        vector<int> increaser;
        int sum = 1;
        int num = 2;
        int inc = 1;
        while(num <= 9)
        {
            sum = sum*10 + num;
            inc = inc*10 + 1;
            special.push_back(sum);
            increaser.push_back(inc);
            num++;
        }
        for(int i = 0 ; i<special.size() ; i++) cout << increaser[i] << " ";
        vector<int> all;
        int index = 0;
        for(int i = 7 ; i>=0; i--)
        {
            int count = 0;
            int num = special[index];
            int incu = increaser[index];
            while(count <= i)
            {
                all.push_back(num);
                num+=incu;
                count++;
            }
            index++;
        }

        vector<int> finalans;

        for(int i = 0 ; i<all.size() ; i++)
        {
            if(all[i] >= low && all[i] <= high) finalans.push_back(all[i]);
        }
        
        return finalans;
    }
};