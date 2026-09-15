class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i = 0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        for(auto &[pos, spe] : cars){
            double time = (double)(target-pos)/spe;

            if(st.empty()) st.push(time);

            else if(time > st.top()){
                st.push(time);
            }
        }

        return st.size();
    }
};