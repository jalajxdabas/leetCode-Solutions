class Solution {
public:
    
    bool isPerfectSquare(int num) {
        int s = 1;
        int e = num;
        while(s<=e){
            long mid = s+((e-s)/2);
            long ans = mid*mid;
            if (ans==num) return true;
            if(ans<num){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return false;
    }
};