class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        int count = 0;

        int i = 0;
        int j = 0;
        int n = fruits.size();

        while(j < n){

            mp[fruits[j]]++;
            count++;

            while(mp.size() > 2 && i < n){
                mp[fruits[i]]--;
                count--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

            maxi = max(count, maxi);
            j++;
        }
        return maxi;
    }
};