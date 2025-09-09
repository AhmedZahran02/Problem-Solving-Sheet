// Made by AOZPROGRAMMING - All Rights Reserved :)
// my solution is different to anything you will every see becasue i am diff

#include <bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile()                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

typedef long long ll;

using namespace std;

ll getaprimefactors(ll n)
{
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            if (i > 2)
                return i;
        }
    }
    return n;
}

// i found that any prime number as a cathetus always the other 2 diagonals is m and m+1
// where m is got by i^2 + (i-1)^2 and i is ceil(n/2)

void solve()
{
    ll n;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << -1 << endl;
        return;
    }
    ll prime = getaprimefactors(n);
    if (prime == 1)
    {
        ll factor = n / 4;
        cout << 3 * factor << " " << 5 * factor << endl;
    }
    else if (prime > 2)
    {
        ll factor = n / prime;
        ll i = (prime + 1) / 2;
        ll c = (i * i) + ((i - 1) * (i - 1));
        cout << (c - 1) * factor << " " << c * factor << endl;
    }
}

int main()
{
    fast1();
    fast2();
    // infile();
    //-------------------------------------------
    int t = 1;
    // cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
