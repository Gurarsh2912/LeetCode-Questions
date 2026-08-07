class Solution {
public:
    int findPar(vector<int> &par, int i){
        if(par[i]==i){
            return i;
        }
        par[i] = findPar(par, par[i]);
        return par[i];
    }

    void Union(int u, int v, vector<int> &par, vector<int> &rank){
        int pu = findPar(par, u);
        int pv = findPar(par, v);
        if(pu==pv){
            return;
        }

        if(rank[pu]==rank[pv]){
            par[pv] = pu;
            rank[pu]++;
        }
        else if(rank[pu]>rank[pv]){
            par[pv] = pu;
        }
        else{
            par[pu] = pv;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> par(n);
        for(int i=0; i<n; i++){
            par[i] = i;
        }

        vector<int> rank(n, 0);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            Union(u, v, par, rank);
        }

        return findPar(par, source)==findPar(par, destination);
    }
};