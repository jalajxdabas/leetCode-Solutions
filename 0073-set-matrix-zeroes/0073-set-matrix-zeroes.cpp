class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int> > index;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    index.push_back(make_pair(i, j));
                }

                else{
                    continue;
                }
                
            }
        }

        for(auto i: index){
            int r = i.first;
            int c = i.second;

            for(int x=0;x<matrix.size();x++){
                for(int j=0;j<matrix[0].size();j++){
                    if(x == r || j ==c){
                        matrix[x][j] = 0;
                    }
                }
            }
        }
    }
};