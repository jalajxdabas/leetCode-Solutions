class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();


        vector<int> rightL(n);
        vector<int> leftR(n);

        for(int i=0; i<n; i++){
            if(dominoes[i] == 'L') leftR[i] = -1;
            else if(dominoes[i] == 'R') leftR[i] = i;
            else leftR[i] = i > 0 ? leftR[i-1] : -1;
        }

        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L') rightL[i] = i;
            else if(dominoes[i] == 'R') rightL[i] = -1;
            else rightL[i] = i < n-1 ? rightL[i+1] : -1;
        }

        string result(n, '.');
        for(int i=0; i<n; i++){
            int left = abs(i-leftR[i]);
            int right = abs(i-rightL[i]);

            if(leftR[i] == rightL[i]) result[i] = '.';
            else if(leftR[i] == -1) result[i] = 'L';
            else if(rightL[i] == -1) result[i] = 'R';
            else if(left == right) result[i] == '.';
            else result[i] = left > right? 'L':'R';
        }

        return result;
    }
};