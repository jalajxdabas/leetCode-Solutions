class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        

        for(int n: nums){
            if(first == n || second == n || third == n) continue;

            if(n > first){
                third = second;
                second = first;
                first = n;
            }
            else if(n > second){
                third = second;
                second = n;
            }
            else if(n > third){
                third = n;
            }
            else continue;
        }

        if(third == LONG_MIN) return first;

        return third;
    }
};