class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        int n = classes.size();
        priority_queue<P> maxi;

        for(int i=0; i<n; i++){
            double curr = (double)classes[i][0] / classes[i][1];
            double next = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = next - curr;
            maxi.push({delta, i});

        }


        while(k--){
            auto top = maxi.top();
            maxi.pop();
            int i = top.second;

            classes[i][0]++;
            classes[i][1]++;
            double curr = (double)classes[i][0] / classes[i][1];
            double next = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = next - curr;
            maxi.push({delta, i});


        }

        double result = 0.0;
        for(int i=0; i<n; i++){
            result += (double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};