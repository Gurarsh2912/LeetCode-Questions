class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int idx){
        if(idx == word.size()){
            return true;
        }

        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]!=word[idx]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = (dfs(board, row+1, col, word, idx+1) ||
                    dfs(board, row-1, col, word, idx+1) ||
                    dfs(board, row, col+1, word, idx+1) ||
                    dfs(board, row, col-1, word, idx+1));
                    
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if (dfs(board, i, j, word, 0)){ 
                    return true;
                }
            }
        }
        return false;
    }
};