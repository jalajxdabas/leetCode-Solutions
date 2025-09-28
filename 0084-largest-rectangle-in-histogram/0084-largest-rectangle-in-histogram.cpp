class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev = prevSmallerElement(arr);
        vector<int> next = nextSmallerElement(arr);

        int area = 0;
        for(int i=0; i<n; i++){
            int height = arr[i];
            if(next[i] == -1) next[i] = n;
            int width = next[i] - prev[i] - 1;
            int currArea = height * width;
            area = max(area, currArea);
        }
        return area;
    }
};
