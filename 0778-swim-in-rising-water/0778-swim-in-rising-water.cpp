class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0,0});

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(vis[r][c]) continue;

            vis[r][c] = true;

            if(r==n-1 && c==n-1) return time;

            for(int k = 0; k<4; k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr<0 || nc<0 || nr>=n || nc>=n){
                    continue;
                }

                if(!vis[nr][nc]){
                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};