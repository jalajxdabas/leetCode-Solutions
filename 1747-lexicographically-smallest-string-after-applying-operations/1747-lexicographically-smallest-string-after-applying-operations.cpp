class Solution {
public:
    void rotate( string &s, int b){
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s)+b);
        reverse(begin(s)+b, end(s));
    }
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;

        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr < ans) ans = curr;

            string temp = curr;
            for(int i=1; i<curr.size(); i+=2){
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if(!vis.count(temp)){
                vis.insert(temp);
                q.push(temp);
            }

            rotate(curr, b);
            if(!vis.count(curr)){
                vis.insert(curr);
                q.push(curr);
            }
        }

        return ans;

    }
};