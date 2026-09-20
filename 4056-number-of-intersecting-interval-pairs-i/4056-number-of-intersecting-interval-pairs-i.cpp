class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for(auto &interval: intervals){
            int st = interval[0];
            int end = interval[1];
            while(!pq.empty() && pq.top() < st){
                pq.pop();
            }
            ans+=pq.size();

            pq.push(end);
        }
        return ans;
    }
};