// Made by AOZPROGRAMMING - All Rights Reserved :)

#include <bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile()                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define all(v) v.begin(), v.end()
#define sortv(vec) sort(all(vec))                                                    // sort vector
#define getdiff(v1, v2, dist) set_difference(all(v1), all(v2), back_inserter(dist)); // search for v1 in v2 if v is empty without order else use search(v1,v2)
typedef long long ll;
typedef unsigned long long ull;
const double pi = 3.14159265358979323846;

using namespace std;

bool check(ll x, ll y, vector<bool> &rows, vector<bool> &cols, vector<bool> &diag, vector<bool> &reversedDiag)
{
    ll diagIndex = y - x;
    if (diagIndex < 0)
    {
        diagIndex = abs(diagIndex) + 7;
    }
    if (!rows[x] && !cols[y] && !diag[diagIndex] && !reversedDiag[x + y])
        return true;
    return false;
}

void toggleQueen(ll x, ll y, vector<bool> &rows, vector<bool> &cols, vector<bool> &diag, vector<bool> &reversedDiag)
{
    rows[x] = !rows[x];
    cols[y] = !cols[y];
    ll diagIndex = y - x;
    if (diagIndex < 0)
    {
        diag[abs(diagIndex) + 7] = !diag[abs(diagIndex) + 7];
    }
    else
    {
        diag[diagIndex] = !diag[diagIndex];
    }
    reversedDiag[x + y] = !reversedDiag[x + y];
}

void recurse(ll col, ll startRow, ll startCol, vector<bool> &rows, vector<bool> &cols, vector<bool> &diag, vector<bool> &reversedDiag, vector<ll> &sol, ll &solCount)
{
    if (col == startCol)
    {
        sol.push_back(startRow);
        recurse(col + 1, startRow, startCol, rows, cols, diag, reversedDiag, sol, solCount);
        sol.pop_back();
    }
    if (col == 8)
    {
        cout << setw(2) << solCount << "      ";
        for (int i = 0; i < sol.size() - 1; i++)
        {
            cout << sol[i] + 1 << " ";
        }
        cout << sol[sol.size() - 1] + 1 << endl;
        solCount++;
        return;
    }
    for (ll rowIndex = 0; rowIndex < 8; rowIndex++)
    {
        if (check(rowIndex, col, rows, cols, diag, reversedDiag))
        {
            toggleQueen(rowIndex, col, rows, cols, diag, reversedDiag);
            sol.push_back(rowIndex);
            recurse(col + 1, startRow, startCol, rows, cols, diag, reversedDiag, sol, solCount);
            sol.pop_back();
            toggleQueen(rowIndex, col, rows, cols, diag, reversedDiag);
        }
    }
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    vector<bool> rows(8, 0);
    vector<bool> cols(8, 0);
    vector<bool> diag(15, 0);
    vector<bool> reversedDiag(15, 0);
    vector<ll> sol;
    ll solCount = 1;
    toggleQueen(x, y, rows, cols, diag, reversedDiag);
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl
         << endl;
    recurse(0, x, y, rows, cols, diag, reversedDiag, sol, solCount);
}

int main()
{
    fast1();
    fast2();
    // infile();
    //-------------------------------------------
    int t = 1;
    cin >> t;
    while (t)
    {
        solve();
        t--;
        if (t > 0)
            cout << endl;
    }
    return 0;
}
