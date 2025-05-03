class Solution {
public:
    int find(vector<int> &tops, vector<int>& bottoms, int val){
        int n = tops.size();
        int top = 0;
        int bottom = 0;

        for(int i=0; i<n; i++){
            if(tops[i] != val && bottoms[i] != val) return -1;
            else if(tops[i] != val) top++;
            else if(bottoms[i] != val) bottom++;
        }
        return min(top, bottom);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;

        for(int i=1; i<7; i++){
            int swaps = find(tops, bottoms, i);

            if(swaps != -1) result = min(result, swaps);
        }

        return result == INT_MAX ? -1 : result;
    }
};