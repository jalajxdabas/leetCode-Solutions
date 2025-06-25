class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;
        long long l = -1e10;
        long long r = 1e10;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long countSmallest = findCountSmallest(nums1, nums2, mid);

            if (countSmallest >= k) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    long long findCountSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct) {
        long long productCount = 0;
        int n = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) {
                if (midProduct >= 0) productCount += n;
                // else 0
            } 
            else if (nums1[i] > 0) {
                int l = 0, r = n - 1, m = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if (product <= midProduct) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                productCount += (m + 1);
            } 
            else { // nums1[i] < 0
                int l = 0, r = n - 1, m = n;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if (product <= midProduct) {
                        m = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                productCount += (n - m);
            }
        }
        return productCount;
    }
};
