class Solution {
    vector<vector<char>> board;
    bool checkCol(int r, int c) {
        int val = board[r][c];
        for (int i = 0; i < 9; i++) {
            if (i == r)
                continue;
            if (board[i][c] == val)
                return false;
        }
        return true;
    }
    bool checkGrid(int r, int c) {
        int val = board[r][c];
        int sRow = (r / 3) * 3, sCol = (c / 3) * 3;
        for (int i = sRow; i < sRow + 3; i++) {
            for (int j = sCol; j < sCol + 3; j++) {
                if (i == r && j == c)
                    continue;
                if (board[i][j] == val)
                    return false;
            }
        }
        return true;
    }
    bool checkRow(int r, int c) {
        int val = board[r][c];
        for (int i = 0; i < 9; i++) {
            if (i == c)
                continue;
            if (board[r][i] == val)
                return false;
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        this->board = board;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (!checkCol(i, j) || !checkRow(i, j) || !checkGrid(i, j))
                    return false;
            }
        }
        return true;
    }
};