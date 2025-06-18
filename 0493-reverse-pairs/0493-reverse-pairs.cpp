class Solution {
public:
    int countPairs(vector<int>& nums, int low, int mid, int high){
        int count = 0;
        int j = mid + 1;

        for(int i=low; i<=mid; i++){
            while(j <=high && (long long)nums[i] > 2LL * nums[j]) j++;

            count += (j-(mid+1));
        }
        return count;

    }
    void merge(vector<int> &nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;

        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }

        while(left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for(int i=low; i<=high; i++){
            nums[i] = temp[i - low];
        }
        
    }
    int mergeSort(vector<int> &nums, int low, int high){
        if(low >= high) return 0;
        int mid = low + (high - low)/2;
        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);

        return count;

    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};