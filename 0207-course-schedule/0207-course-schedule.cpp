class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis,
             vector<bool> &rec) {

        vis[node] = true;
        rec[node] = true;

        for (int neigh : adj[node]) {

            if (!vis[neigh]) {
                if (dfs(neigh, adj, vis, rec))
                    return true;
            }
            else if (rec[neigh]) {
                return true;
            }
        }

        rec[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, rec))
                    return false;
            }
        }

        return true;
    }
};