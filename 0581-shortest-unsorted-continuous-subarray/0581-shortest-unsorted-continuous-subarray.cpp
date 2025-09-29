class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = n+1;
        int right = -1;

        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                left = i;
                break;
            }
        }

        if(left == n+1) return 0;

        for(int i=n-1; i>0; i--){
            if(arr[i] < arr[i-1]){
                right = i;
                break;
            }
        }

        int maxi = arr[left];
        int mini = arr[right];

        for(int i=left+1; i<=right; i++){
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }


        for(int i=0; i<left; i++){
            if(arr[i] > mini){
                left = i;
                break;
            }
        }

        for(int i=n-1; i>right; i--){
            if(arr[i] < maxi){
                right = i;
                break;
            }
        }

        return right-left+1;
    }
};