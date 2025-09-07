class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        int n = time.size();
        vector<int> temp(60, 0);

        for(int i=0; i<n; i++){
            int a = time[i] % 60;

            if(a == 0){
                count += temp[a];
            }
            else{
                count += temp[60-a];
            }
            temp[a]++;
        }
        return count;
    }
};