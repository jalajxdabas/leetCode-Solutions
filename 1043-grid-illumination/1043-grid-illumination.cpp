class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> x, y, p_diag, s_diag;
        set<pair<int, int>> s;

        for(auto &i: lamps){
            if (s.count({i[0], i[1]})) continue; 
            s.insert({i[0], i[1]});

            x[i[0]]++;
            y[i[1]]++;
            p_diag[i[0] + i[1]]++;
            s_diag[i[0] - i[1]]++;
        }

        for(auto &q: queries){
            if(x[q[0]] > 0 || y[q[1]] > 0 || p_diag[q[0] + q[1]] > 0 ||s_diag[q[0] - q[1]] > 0){
                ans.push_back(1);
                for(int j=-1; j<2; j++){
                    for(int k=-1; k<2; k++){
                        int qx = q[0] + j;
                        int qy = q[1] + k;

                        if(qx >= 0 && qx < n && qy >= 0 && qy < n && s.count({qx, qy})){
                            s.erase({qx, qy});
                            x[qx]--;
                            y[qy]--;
                            p_diag[qx+qy]--;
                            s_diag[qx-qy]--;
                        }
                    }
                }
            }
            else{
                ans.push_back(0);
            }
            
        }

        return ans;
        
    }
};