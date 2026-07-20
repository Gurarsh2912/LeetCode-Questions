class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> clr(graph.size(), -1);
        int n = graph.size();
        for(int i = 0; i<n; i++){
            if(clr[i]!=-1)continue;
            q.push(i);
            clr[i] = 0;
            while(q.size()){
                int curr = q.front();
                q.pop();
                for(int v:graph[curr]){
                    if(clr[v]==-1){
                        clr[v] = 1-(clr[curr]);
                        q.push(v);
                    } else{
                        if(clr[v]==clr[curr]) return false;
                    }
                }
            }
        }
        return true;
    }
};