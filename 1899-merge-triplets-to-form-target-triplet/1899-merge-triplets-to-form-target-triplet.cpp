class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;

        for(auto& triplet : triplets){
            int f = triplet[0];
            int s = triplet[1];
            int t = triplet[2];
            if(f > target[0] || s > target[1] || t > target[2]){
                continue;
            }
            
            else {
                first = max(f, first);
                second = max (second, s);
                third = max(third, t);
            }
        }
        return (first==target[0] && second==target[1] && target[2]==third);
    }
};