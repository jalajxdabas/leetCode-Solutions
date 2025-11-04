class Solution {
public: 
    int solve(array<pair<int,int>, 51> &arr1, int k){
        auto arr = arr1;
        sort(arr.begin(), arr.end(), greater<pair<int,int>>());
        int sm = 0;
        for(int i = 0; i < k; i++){
            auto [f, val] = arr[i];
            if(f == 0) break;
            sm += val*f;
        }
        return sm;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        array<pair<int,int>, 51> arr;
        vector<int> ans;
        arr.fill({0, 0});
        for(int i = 0; i < k; i++){
            arr[nums[i]].first += 1;
            arr[nums[i]].second = nums[i];
        }
        int n = nums.size();
        ans.push_back(solve(arr, x));
        for(int i = k; i  < n; i++){
            arr[nums[i-k]].first--;
            arr[nums[i]].first++;
            arr[nums[i]].second = nums[i];
            ans.push_back(solve(arr, x));
        }
        return ans;
    }
};