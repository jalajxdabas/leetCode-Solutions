class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;

        while(left < right){
            int h = min(height[left], height[right]);
            int b = right - left;
            ans = max(ans, (h*b));

            if(height[left] < height[right]) left++;
            else right--;
        }
        return ans;

    }
};