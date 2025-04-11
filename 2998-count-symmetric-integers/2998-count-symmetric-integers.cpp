class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for(int i=low; i<=high; i++){
            int num = i;
            if(i>=10 && i<=99 && i%11 == 0) ans++;
            else if(num>=1000 && num<=9999){
                int first = num/1000;
                int second = (num/100)%10;
                int third = (num/10)%10;
                int fourth = (num)%10;

                if(first+second == third+fourth) ans++;
            }
        }
        return ans;
    }
};