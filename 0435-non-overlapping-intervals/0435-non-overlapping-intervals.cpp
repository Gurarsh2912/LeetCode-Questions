class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int ans = 0;
        int prev = intervals[0][1];
        for(auto& vec : intervals){
            int u = vec[0];
            int v = vec[1];

            if(u<prev){
                ans++;
                prev = min(prev, v);
            }

            else{
                prev = v;
            }
        }
        return ans-1;
    }
};