#define all(v) v.begin(),v.end()
typedef long long ll;

using namespace std;

bool sortBySecRef(const int* a, const int* b)
{
    if (*a != *b) {
        return *a > *b;
    }
    return *a > *b;
}

bool sortBySecRef2(const int* a, const int* b)
{
    if (*a != *b) {
        return *a < *b;
    }
    return *a < *b;
}

class Solution {

public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid);
        // upper half
        for (int j = 1; j < grid.size(); j++) {
            vector<int*> ar(grid.size() - j);
            for (int i = 0; i < (grid.size() - j); i++) {
                ar[i] = &grid[i][j + i];
            }
            sort(all(ar), sortBySecRef2);
            for (int i = 0; i < (grid.size() - j); i++) {
                ans[i][j + i] = *ar[i];
            }
        }
        // lower half
        for (int i = 0; i < grid.size(); i++) {
            vector<int*> ar(grid.size() - i);
            for (int j = 0; j < (grid.size() - i); j++) {
                ar[j] = &grid[i+j][j];
            }
            sort(all(ar), sortBySecRef);
            for (int j = 0; j < (grid.size() - i); j++) {
                ans[i + j][j] = *ar[j];
            }
        }
        return ans;
    }
};