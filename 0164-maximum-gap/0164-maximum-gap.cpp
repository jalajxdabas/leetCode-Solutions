class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> maxi;

        if(n < 2) return 0;

        for(int i: nums) maxi.push(i);

        int ans = 0;

        while(maxi.size() > 1){
            int top = maxi.top();
            maxi.pop();
            int temp = maxi.top();
            
            ans = max(ans, top-temp);

        }
        return ans;


    }
};