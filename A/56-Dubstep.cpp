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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//least common multiple
long long lcm(int a, int b)
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

void solve() {
    string s;
    string s2="";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {
            i += 2;
            if (s2.empty() || s2[s2.length() - 1] == ' ')
            {

            }
            else
            {
                s2 += ' ';
            }
        }
        else
        {
            s2 += s[i];
        }
    }
    cout << s2 << endl;
}

int main() {
    fast1();
    fast2();
    //infile();
    //------------------------------------------- 
    int t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}