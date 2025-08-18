class Solution {
public:
    double epsilon = 0.1;

    bool solve(vector<double> cards){
        if (cards.size() == 1) {
        return abs(cards[0] - 24) <= epsilon;
        }
        int n = cards.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;


                vector<double> temp;

                for(int k=0; k<n; k++){
                    if(i != k && j!= k ) temp.push_back(cards[k]);
                }

                double a = cards[i];
                double b = cards[j];

                vector<double> poss = {a+b, a-b, b-a, a*b};

                if(abs(a) > 0.0) poss.push_back(b/a);
                if(abs(b) > 0.0) poss.push_back(a/b);

                for(double val: poss){
                    temp.push_back(val);
                    if(solve(temp) == true) return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        int n = cards.size();

        for(int i=0; i<n; i++){
            nums.push_back(1.0 * cards[i]);
        }

        return solve(nums);

    }
};