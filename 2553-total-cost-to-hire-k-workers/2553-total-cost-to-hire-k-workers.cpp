class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;

        long long sum = 0;
        int n = costs.size();
        int low = 0, high = n - 1;

        
        for (int i = 0; i < candidates && low <= high; i++) {
            left.push(costs[low++]);
        }
        for (int i = 0; i < candidates && low <= high; i++) {
            right.push(costs[high--]);
        }

        
        while (k--) {
            int l = left.empty() ? INT_MAX : left.top();
            int r = right.empty() ? INT_MAX : right.top();

            if (l <= r) {
                sum += l;
                left.pop();
                if (low <= high) {
                    left.push(costs[low++]);
                }
            } else {
                sum += r;
                right.pop();
                if (low <= high) {
                    right.push(costs[high--]);
                }
            }
        }

        return sum;
    }
};
