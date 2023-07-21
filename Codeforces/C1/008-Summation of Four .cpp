// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>

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

bool isPrime(ll num) {
    if (num == 2) return 1;
    if (num < 2 || num % 2 == 0) return 0;

    for (ll i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

ll getSmallerPrime(ll n) {
    if (isPrime(n))
    {
        return n;
    }
    else {
        for (ll i = n - 1; i >= 2; i--)
        {
            if (isPrime(i))
            {
                return i;
            }
        }
    }
}

ll getLargerPrime(ll n) {
    if (isPrime(n))
    {
        return n;
    }
    else {
        for (ll i = n + 1; i <= 2 * n; i++)
        {
            if (isPrime(i))
            {
                return i;
            }
        }
    }
}

void solve() {
    ll n;
    while (cin >> n)
    {
        if (n < 8)
        {
            cout << "Impossible." << endl;
        }
        else {
            if (n == 8)
            {
                cout << "2 2 2 2" << endl;
                continue;
            }
            ll num = n;
            ll num1 = num / 2;
            ll num2 = num - num1;
            ll ans1 = getSmallerPrime(num1 - 1);
            num -= ans1;
            num1 = num / 2;
            num2 = num - num1;
            ll ans2 = getSmallerPrime(num1 - 1);
            num -= ans2;
            while (!isPrime(num - 3) && !isPrime(num - 2))
            {
                ll newans2 = getLargerPrime(ans2 + 1);
                num += ans2 - newans2;
                ans2 = newans2;
            }
            if (isPrime(num - 3))
            {
                cout << ans1 << " " << ans2 << " " << num - 3 << " " << 3 << endl;
                if (!isPrime(ans1) || !isPrime(ans2) || !isPrime(num - 3))
                {
                    cout << "Failed !!!!!!!!!!" << endl;
                    return;
                }
            }
            else {
                cout << ans1 << " " << ans2 << " " << num - 2 << " " << 2 << endl;
                if (!isPrime(ans1) || !isPrime(ans2) || !isPrime(num - 2))
                {
                    cout << "Failed !!!!!!!!!!" << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    ll t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
