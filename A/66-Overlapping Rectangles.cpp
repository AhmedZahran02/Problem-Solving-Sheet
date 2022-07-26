// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define sortv(vec) sort(vec.begin(),vec.end()) //sort vector
typedef long long ll;
typedef unsigned long long ull;
//const double pi = 3.14159265358979323846;

using namespace std;

//long long int faster pow func
ll fastpow(ll b, ll e) {
    if (!e)
    {
        return 1;
    }
    if (e & 1)
    {
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}
//greatest common divisor
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//least common multiple
ll lcm(ll a, ll b)
{
    if (a == 1 && b == 1)
    {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}
//factorial
ll factorial(ll n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
//minimum
ll mini(ll a, ll b) {
    if (a >= b) {
        return b;
    }
    else {
        return a;
    }
}
//absolute val
ll posi(ll a) {
    if (a >= 0) {
        return a;
    }
    else {
        ll b = a * (-1);
        return b;
    }
}
// sort by second pair
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
//Modular multiplicative inverse a=3 m=11 out=4 3*4
int mpow(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
}
//decimal to binary
string dtb(ll n)
{
    string r;
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}
//powmod
ll PowMod(ll b, ll e, ll M) {
    if (!e)
    {
        return 1;
    }
    ll p = PowMod((b * b) % M, e / 2, M);
    return (e % 2) ? (p * b) % M : p;
}

vector<ll> primefactors(ll n) {
    vector<ll> x;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            x.push_back(i);
        }
    }
    if (n != 1)
    {
        x.push_back(n);
    }
    return x;
}

vector<ll> factors(ll n) {
    vector<ll> x;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            x.push_back(i);
            x.push_back(n / i);
        }
    }
    if (sqrt(n) == int(sqrt(n)))
    {
        x.pop_back();
    }
    sortv(x);
    return x;
}

int getTrace(vector<vector<int>>& graph, int V)
{
    int trace = 0;
    for (int i = 0; i < V; i++)
        trace += graph[i][i];
    return trace;
}

// multiplication of matrix c = a x b
void multiply(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < V; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

void mapdfs(vector<vector<int>>& vec, vector<vector<bool>>& vis, int i, int j, int n, int m) {
    if (i >= 0 && j >= 0 && i < n && j < m)
    {
        if (vec[i][j] == '1' && vis[i][j] == false)
        {
            vis[i][j] = 1;
            mapdfs(vec, vis, i + 1, j, n, m);
            mapdfs(vec, vis, i - 1, j, n, m);
            mapdfs(vec, vis, i, j + 1, n, m);
            mapdfs(vec, vis, i, j - 1, n, m);
            /* dfs(vec, vis, i + 1, j + 1, n, m);
             dfs(vec, vis, i + 1, j - 1, n, m);
             dfs(vec, vis, i - 1, j + 1, n, m);
             dfs(vec, vis, i - 1, j - 1, n, m);*/
        }
    }
}
//vector<int>topsort;
void dfs(int start, vector<vector<int>>& vec, vector<bool>& vis)
{
    vis[start] = true;
    for (int j = 0; j < vec[start].size(); j++) {
        int item = vec[start][j];
        if (!vis[item]) {
            dfs(item, vec, vis);
        }
    }
    //topsort.push_back(start);
}
//vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,47 , 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

//int Dijkstra(vector<vector<pair<ll, pair<ll, ll>>>> adjList, int src, int dest = -1)    // O(E logV)
//{
//    int n = adjList.size();
//    vector<int> dist(n, INT_MAX), prev(n, -1);
//    dist[src] = 0;
//
//    priority_queue<pair<ll, pair<ll, ll>>> q;
//    q.push(make_pair(0, make_pair(-1, src)));
//
//    while (!q.empty()) {
//        pair<ll, pair<ll, ll>> e = q.top();
//        q.pop();
//        int w = e.first, from = e.second.first, to = e.second.second;
//        if (w > dist[to]) continue;    // some other state reached better
//
//        prev[to] = from;
//
//        for (int i = 0; i < adjList[to].size(); ++i) {
//            pair<ll, pair<ll, ll>> ne = adjList[to][i];
//            int neww = ne.first, nefrom = ne.second.first, neto = ne.second.second;
//
//            if (dist[neto] > dist[nefrom] + neww) {
//                neww = dist[neto] = dist[nefrom] + neww;
//                q.push(ne);
//            }
//        }
//    }
//
//    return dist[dest] == INT_MAX ? -1 : dist[dest];
//}
bool cl = 0;
void solve() {
    vector<pair<double, double>> x;
    vector<pair<double, double>> y;
    int i = 0;
    int t = 2;
    while (t>0)
    {
        double p1, p2;
        cin >> p1 >> p2;
        x.push_back({ 0,0 });
        y.push_back({ 0,0 });
        x[i].first = p1;
        y[i].first = p2;
        cin >> p1 >> p2;
        x[i].second = p1;
        y[i].second = p2;
        i++;
        t--;
    }
    bool d = 0;
    int x0, x1, y0, y1;
    int mn = min(x[0].first, x[1].first);
    int mn2= min(y[0].first, y[1].first);
    if (mn==x[0].first)
    {
        if (x[0].second>x[1].first)
        {
            if (mn2==y[0].first)
            {
                if (y[0].second > y[1].first)
                {
                    x0 = x[1].first;
                    y0 = y[1].first;
                    x1 = min(x[0].second,x[1].second);
                    y1 = min(y[0].second,y[1].second);
                }
                else
                {
                    d = 1;
                }
            }
            else
            {
                if (y[1].second > y[0].first)
                {
                    x0 = x[1].first;
                    y0 = y[0].first;
                    x1 = min(x[0].second,x[1].second);
                    y1 = min(y[1].second,y[0].second);
                }
                else
                {
                    d = 1;
                }
            }
        }
        else
        {
            d = 1;
        }
    }
    else
    {
        if (x[1].second > x[0].first)
        {
            if (mn2 == y[0].first)
            {
                if (y[0].second > y[1].first)
                {
                    x0 = x[0].first;
                    y0 = y[1].first;
                    x1 = min(x[1].second,x[0].second);
                    y1 = min(y[0].second,y[1].second);
                }
                else
                {
                    d = 1;
                }
            }
            else
            {
                if (y[1].second > y[0].first)
                {
                    x0 = x[0].first;
                    y0 = y[0].first;
                    x1 = min(x[1].second,x[0].second);
                    y1 = min(y[1].second,y[0].second);
                }
                else
                {
                    d = 1;
                }
            }
        }
        else
        {
            d = 1;
        }
    }
    if (cl)
    {
        cout << endl;
    }
    else
    {
        cl = 1;
    }
    if (d)
    {
        cout << "No Overlap" << endl;
    }
    else
    {
        cout << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
    }
}

int main() {
    fast1();
    fast2();
    //infile();
    //------------------------------------------- 
    int t = 1;
    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}