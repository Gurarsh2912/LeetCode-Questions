class Solution {
public:
    void solve(vector<int>& candidates, int start, int target,
               vector<int>& path, vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(path);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            if(i > start && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] > target)
                break;

            path.push_back(candidates[i]);

            solve(candidates, i + 1, target - candidates[i],
                  path, ans);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> path;

        solve(candidates, 0, target, path, ans);

        return ans;
    }
};