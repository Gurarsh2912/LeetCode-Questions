class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int> &path, vector<vector<int>> &paths, int u){
        path.push_back(u);
        if(u==graph.size()-1){
            paths.push_back(path);
        }

        else {
            for(int v : graph[u]){
                dfs(graph, path, paths, v);
            }
        }

        path.pop_back();
        return;

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;

        dfs(graph, path, paths, 0);
        return paths;
    }
};