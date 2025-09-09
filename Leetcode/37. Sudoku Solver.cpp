class Solution {
private:
    bool recurse(int row, int col, vector<vector<char>>& board, vector<array<bool, 9>>& rows, vector<array<bool, 9>>& cols, vector<array<bool, 9>>& boxes) {
        if (row == 9) 
            return true;
        
        int rowNumber = int(row / 3);
        int colNumber = int(col / 3);
        if (board[row][col] == '.') {
            for (char ch = '1'; ch <= '9'; ch++) {
                int number = ch - '1';
                if (rows[row][number] && cols[col][number] && boxes[rowNumber * 3 + colNumber][number]) {
                    board[row][col] = ch;
                    // apply effect on row, col and square
                    rows[row][number] = false;
                    cols[col][number] = false;
                    boxes[rowNumber * 3 + colNumber][number] = false;

                    if (recurse(row + int((col + 1) / 9), (col + 1) % 9, board, rows, cols, boxes)) return true;
                    
                    // backtrack
                    board[row][col] = '.';
                    rows[row][number] = true;
                    cols[col][number] = true;
                    boxes[rowNumber * 3 + colNumber][number] = true;
                }
            }
        }
        else {
            if (recurse(row + int((col + 1) / 9), (col + 1) % 9, board, rows,cols,boxes)) return true;
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<array<bool, 9>> rows(9, array<bool, 9>{true, true, true, true, true, true, true, true, true});
        vector<array<bool, 9>> cols(9, array<bool, 9>{true, true, true, true, true, true, true, true, true});
        vector<array<bool, 9>> boxes(9, array<bool, 9>{true, true, true, true, true, true, true, true, true});

        // deduce easy cases
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++)
            {

                switch (board[row][col])
                {
                case '.':
                    break;
                default:
                    int number = board[row][col] - '1';
                    // row
                    rows[row][number] = false;
                    // col
                    cols[col][number] = false;
                    // square
                    int rowNumber = int(row / 3);
                    int colNumber = int(col / 3);
                    boxes[rowNumber*3+colNumber][number] = false;
                    break;
                }
            }
        }
        // recurse
        recurse(0, 0, board, rows,cols,boxes);
    }
};