// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() {
    string from, to;
    while (cin >> from >> to)
    {
        int startx = from[0] - 'a';
        int starty = from[1] - '0' - 1;

        int endx = to[0] - 'a';
        int endy = to[1] - '0' - 1;

        queue<pair<pair<int, int>, int>>q;

        q.push({ {startx,starty}, 0 });
        int ans = -1;
        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int level = q.front().second;
            q.pop();

            if (x == endx and y == endy)
            {
                ans = level;
                break;
            }

            int xtemp, ytemp;

            int dx[8] = { 2,2,-2,-2,1,1,-1,-1 };
            int dy[8] = { 1,-1,1,-1,2,-2,2,-2 };

            for (int i = 0; i < 8; i++)
            {
                xtemp = x + dx[i]; ytemp = y + dy[i];

                if (xtemp < 8 && ytemp < 8 && xtemp >= 0 && ytemp >= 0)
                {
                    q.push({ {xtemp,ytemp},level + 1 });
                }
            }
        }

        cout << "To get from " << from << " to " << to << " takes " << ans << " knight moves." << endl;
    }
}

int main() {
    int t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
