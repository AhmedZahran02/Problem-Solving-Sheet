//leet code
#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
typedef long long ll;
typedef unsigned long long ull;

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<ll>>ar(n, vector<ll>(n, -1));
        for (int i = 0; i < times.size(); i++)
        {
            ar[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }
        vector<int> d(n, INT_MAX);
        vector<bool> vis(n, 0);
        d[k - 1] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({ k - 1,0 });

        while (!pq.empty())
        {
            pair<int, int>p = pq.top();
            pq.pop();
            for (int i = 0; i < n; i++)
            {
                if (ar[p.first][i] != -1)
                {
                    if (ar[p.first][i] + p.second < d[i]) {
                        pq.push({ i,ar[p.first][i] + p.second });
                        d[i] = ar[p.first][i] + p.second;
                    }
                }
            }
        }
        int mx = INT_MIN;
        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] > mx)
            {
                mx = d[i];
            }
        }
        if (mx == INT_MAX)
        {
            return -1;
        }
        return mx;
    }
};