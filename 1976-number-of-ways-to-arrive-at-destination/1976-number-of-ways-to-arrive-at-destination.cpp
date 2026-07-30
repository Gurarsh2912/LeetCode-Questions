class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        long long MOD = 1e9 + 7;
        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
        > pq;

        pq.push({0, 0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;

            for(auto &[v, wt]: adj[u]){
                long long newD = d+wt;
                if(newD < dist[v]){
                    dist[v] = newD;
                    ways[v] = ways[u];
                    pq.push({newD, v});
                }

                else if(newD == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];

    }
};