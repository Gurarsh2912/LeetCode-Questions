class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
        });

        int remaining = truckSize;
        int answer = 0;

        for(auto& box : boxTypes){

            int take = min(box[0], remaining);

            answer += take * box[1];

            remaining -= take;

            if (remaining == 0) break;
        }

    return answer;

    }
};