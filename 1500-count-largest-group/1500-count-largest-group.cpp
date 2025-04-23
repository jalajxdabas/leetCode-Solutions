class Solution {
public:

    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int count = 0;
        int maxi = 0;

        for(int i=1; i<=n; i++){
            int temp = 0;
            int key = i;
            while(key>0){
                temp += key%10;
                key /= 10;
            }
            mp[temp]++;
            maxi = max(maxi, mp[temp]);
        }

        for(auto i: mp){
            if(maxi == i.second){
                count++;
            }
        }
        return count;


    }
};