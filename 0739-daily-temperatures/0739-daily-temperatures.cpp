class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, 0);

        st.push(n-1);

        for(int i=n-2; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            if(!st.empty()){
                int top = st.top();
                ans[i] = top-i;
            }
            st.push(i);
        }
        return ans;



    }
};