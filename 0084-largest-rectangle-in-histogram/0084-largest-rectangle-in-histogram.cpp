class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;

        int maxi = 0;

        for(int i=0; i<=n; i++){
            int curr = (i == n) ? 0 : heights[i];
            while(!st.empty() && curr < heights[st.top()]){
                int top = heights[st.top()];
                st.pop();
                int h = top;
                int w = (st.empty()) ? i :  i - st.top() - 1;
                int area = w * h;
                maxi = max(area, maxi);
            }

            st.push(i);
        }
        
        return maxi;
    }
};