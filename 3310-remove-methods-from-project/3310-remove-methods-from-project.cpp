class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int u){
        vis[u] = true;
        for(int v: adj[u]){
            if(!vis[v]) dfs(adj, vis, v);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &vec: invocations){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(n, false);
        dfs(adj, vis, k);
        
        vector<int> ans;

        for(auto &vec: invocations){
            int u = vec[0];
            int v = vec[1];
            if(vis[u]==false && vis[v]==true){
                for(int i=0; i<n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};