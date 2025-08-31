class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int, int>> q;
        int m = maze.size();
        int n = maze[0].size();

        maze[e[0]][e[1]] = '+';
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, 1, 0, -1};

        q.push({e[0], e[1]});
        int level =   1;

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int x = p.first + dx[i];
                    int y = p.second + dy[i];

                    if( x < 0 || x >= m || y < 0 || y >= n || maze[x][y]=='+')  continue;

                    if(x == 0 || x == m-1 || y == 0 || y == n-1) return level;

                    q.push({x, y});
                    maze[x][y]='+';
                }
            }
            level++;
        }
        return -1;

    }
};