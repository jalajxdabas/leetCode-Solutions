class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        
        int level = 1;

        while(n >= level){
            count++;
            n -= level;
            level++;
        }
        return count;
    }
};