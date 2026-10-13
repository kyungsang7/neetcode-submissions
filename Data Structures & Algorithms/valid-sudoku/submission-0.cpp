
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> nums;


        for (int i = 0; i < 9; i++) {
            nums.clear();

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (nums.find(board[i][j]) != nums.end()) {
                    return false;
                }

                nums.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 9; i++) {
            nums.clear();

            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }

                if (nums.find(board[j][i]) != nums.end()) {
                    return false;
                }

                nums.insert(board[j][i]);
            }
        }


        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                nums.clear();

                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] == '.') {
                            continue;
                        }

                        if (nums.find(board[x][y]) != nums.end()) {
                            return false;
                        }

                        nums.insert(board[x][y]);
                    }
                }
            }
        }

        return true;
    }
};
