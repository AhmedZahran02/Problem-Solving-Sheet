// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<unordered_map>
//#include <chrono>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
#define getdiff(v1,v2,dist) set_difference(all(v1), all(v2),back_inserter(dist)); // search for v1 in v2 if v is empty without order else use search(v1,v2)
typedef long long ll;
typedef unsigned long long ull;
const double pi = 3.14159265358979323846;

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
//nCr
ll ncr(ll n, ll r) {
    if (r > n - r) r = n - r;
    ll ans = 1;
    ll i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
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
//sort by first pair
bool sortbyfst(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}
// sort by second pair
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
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

int test(vector<int>& ar, int mid) {
    int res = 1;
    int itr = 0;
    for (int i = 1; i < ar.size(); i++)
    {
        if (ar[i] - ar[itr] >= mid)
        {
            res++;
            itr = i;
        }
    }
    return res;
}

ll bs(vector<int>& ar, ll start, ll end, ll val) {
    while (start < end - 1)
    {
        ll mid = start + (end - start) / 2;
        if (test(ar, mid) >= val)
        {
            start = mid;
        }
        else {
            end = mid - 1;
        }
    }
    if (test(ar, end) >= val)
    {
        return end;
    }
    else
    {
        return start;
    }
}

class disjointset {
private:
    int size;
    int* sz;
    int* id;
    int numofcomp;

public:
    disjointset(int size) {
        if (size > 0)
        {
            this->size = size;
            this->numofcomp = size;
            sz = new int[size];
            id = new int[size];

            for (int i = 0; i < size; i++)
            {
                id[i] = i;
                sz[i] = 1;
            }
        }
        else {
            this->size = 0;
            this->numofcomp = 0;
            sz = new int[0];
            id = new int[0];
        }
    }

    int find(int p) {
        int trav = p;
        while (trav != id[trav])
        {
            trav = id[trav];
        }

        while (p != trav) {
            int next = id[p];
            id[p] = trav;
            p = next;
        }

        return trav;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int componentsize(int p) {
        return sz[find(p)];
    }

    int getsize() {
        return size;
    }

    int getnumofcomponents() {
        return numofcomp;
    }

    void unify(int p, int q) {
        int root1 = find(p);
        int root2 = find(q);

        if (root1 == root2)
        {
            return;
        }

        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
        else {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        numofcomp--;
    }
};

//////leet code
//#define all(v) v.begin(),v.end()
//#define sortv(vec) sort(all(vec)) //sort vector
//typedef long long ll;
//typedef unsigned long long ull;
//
//class Solution {
//public:
//
//    int maxSubarraySumCircular(vector<int>& nums) {
//        deque<int>acc(nums.size(), INT_MIN);
//        acc[0] = nums[0];
//        for (int j = 1; j < nums.size(); j++)
//        {
//            acc[j] = nums[j] + acc[j - 1];
//        }
//
//        int max = INT_MIN;
//        for (int i = 0; i <= nums.size(); i++)
//        {
//            for (int j = 0; j < acc.size(); j++)
//            {
//                if (acc[j] > max)
//                {
//                    max = acc[j];
//                }
//            }
//
//            int x = acc.front();
//            acc.pop_front();
//            for (int j = 0; j < acc.size(); j++)
//            {
//                acc[j] -= x;
//            }
//            acc.push_back(x);
//            acc[acc.size() - 1] += acc[acc.size() - 2];
//        }
//        return max;
//    }
//};



void solve() {
    ll n; cin >> n;
    set<ll>ar;
    for (ll i = 0; i < n; i++)
    {
        ll x; cin >> x;
        ar.insert(x);
    }
    if (ar.size() < 3)
    {
        cout << "YES" << endl;
    }
    else if (ar.size() > 3)
    {
        cout << "NO" << endl;
    }
    else {
        vector<ll>arr;
        for (auto i : ar)
        {
            arr.push_back(i);
        }
        if ((arr[0] + arr[2]) / 2.0 == arr[1])
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

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
