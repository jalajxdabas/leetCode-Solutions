class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        if(n%2 == 1){
            ans.push_back(0);
            n -= 1;
        }
        
        int i = 1;
        while(n > 0){
            ans.push_back(i);
            ans.push_back(-i);
            i += 1;
            n -= 2;
        }
        return ans;
    }
};