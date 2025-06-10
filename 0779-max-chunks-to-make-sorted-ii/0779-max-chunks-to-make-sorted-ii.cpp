class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;

        for(int i=0; i<n; i++){
            int lastChunkEnd = nums[i];
            while(!st.empty() && st.top() > nums[i]){
                lastChunkEnd = max(st.top(), lastChunkEnd);
                st.pop();
            }
            st.push(lastChunkEnd);
        }
        return st.size();
    }
};