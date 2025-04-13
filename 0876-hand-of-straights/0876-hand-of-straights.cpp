class Solution {
public:
    bool findNext(int i, vector<int> &hand, int k){
        int n = hand.size();
        int next = hand[i] + 1;
        hand[i] = -1;
        i++;
        int ans = 1;
        while(i<n && ans<k){
            if(next == hand[i]){
                next = hand[i]+1;
                hand[i] = -1;
                ans++;
            }
            i++;
        }
        return ans == k;
    }
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if(n%k) return false;

        sort(hand.begin(), hand.end());
        for(int i=0; i<n; i++){
            if(hand[i] >= 0){
                if(!findNext(i, hand, k)) return false;
            }
        }
        return true;
    }
};