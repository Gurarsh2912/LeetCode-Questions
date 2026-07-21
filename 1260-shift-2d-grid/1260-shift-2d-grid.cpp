class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        int total = n * m;
        k %= total;   // Handle cases where k > total elements

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Convert (i, j) to 1D index
                int index = i * m + j;

                // Find new index after shifting
                int newIndex = (index + k) % total;

                // Convert new index back to (row, col)
                int newRow = newIndex / m;
                int newCol = newIndex % m;

                // Place the element
                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};