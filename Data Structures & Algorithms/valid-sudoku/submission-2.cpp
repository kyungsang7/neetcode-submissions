class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int square[9] = {0};
        int key;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j] == '.'){
                    continue;
                }
                key = (i / 3) * 3 + (j / 3);
                int val = board[i][j] - '1';
                if(row[i] & (1 << val) || col[j] & (1 << val) || square[key] & (1 << val)){
                    return false;
                }
                row[i] = row[i] | (1 << val);
                col[j] = col[j] | (1 << val);
                square[key] = square[key] | (1 << val);
            }
        }
        return true;
    }
};
