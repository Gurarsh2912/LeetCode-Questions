class Solution {
public:
    int extra = 0;
    int findPar(int i, vector<int> &par){
        if(par[i]==i) return i;
        return par[i] = findPar(par[i], par);
    }

    void uni(int u, int v, vector<int> &par, vector<int> &rank){
        int pu = findPar(u, par);
        int pv = findPar(v, par);

        if(pu==pv) {
            extra++;
            return;
        }

        if (rank[pu] > rank[pv])  par[pv] = pu;

        else if (rank[pv] > rank[pu])   par[pu] = pv;

        else{
            par[pv] = pu;
            rank[pu]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        vector<int> rank(n, 0);
        vector<int> par(n);
        for(int i= 0; i<n; i++){
            par[i] = i;
        }

        for(auto &vec : connections){
            int u = vec[0];
            int v = vec[1];

            uni(u, v, par, rank);
        }

        int comp = -1;
        for(int i=0; i<n; i++){
            if(par[i]==i){
                comp++;
            }
        }

        if(extra >= comp){
            return comp;
        }
        return -1;

    }
};