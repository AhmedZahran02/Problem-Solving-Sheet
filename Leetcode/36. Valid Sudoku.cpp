class Solution {
private:
    bool checkRowsAndColsAndBoxes(vector<vector<char>>& board) {
        vector<map<int, bool>> ar(9);
        vector<map<int, bool>> boxes(9);
        int row = 0;
        for (auto line : board) {
            map<int, bool> mp;
            int col = 0;
            for (auto chr : line) {
                if (chr != '.') {
                    if (mp[chr])
                        return false;
                    mp[chr] = true;
                    if (ar[col][chr])
                        return false;
                    ar[col][chr] = true;
                    int boxNumber = 2 * int(row / 3) + int(row / 3) + int(col / 3);
                    if (boxes[boxNumber][chr])
                        return false;
                    boxes[boxNumber][chr] = true;
                }
                col++;
            }
            row++;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRowsAndColsAndBoxes(board);
    }
};