class Solution {
public:
    int solve(int spell, vector<int> &potions, long long success){
        int n = potions.size();
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long product = 1LL * potions[mid] * spell; 

            if(product < success){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int m = potions.size();

        for(int spell : spells){
            int idx = solve(spell, potions, success);
            ans.push_back(m - idx);  
        }
        return ans;
    }
};
