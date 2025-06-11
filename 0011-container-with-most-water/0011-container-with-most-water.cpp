class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;

        while(left < right){
            int h = min(height[left], height[right]);
            int w = right-left;
            int area = h*w;
            ans = max(ans, area);

            if(h == height[left]) left++;
            else right--;
        }
        return ans;
    }
};