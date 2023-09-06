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

vector<int> primes =
{ 2,	3,	5,	7,	11	,13,	17,	19,	23,	29	,31	,37,	41,	43	,47,	53	,59,	61	,67	,71
,73,	79,	83,	89	,97	,101,	103,	107,	109	,113,	127,	131,	137	,139	,149,	151	,157,	163	,167,	173
,179,	181,	191,	193,	197,	199	,211,	223	,227,	229	,233	,239,	241,	251,	257,	263	,269,	271,	277	,281
,283,	293,	307,	311,	313	,317	,331	,337	,347,	349	,353,	359	,367	,373	,379	,383	,389	,397,	401,	409
,419,	421,	431,	433,	439,	443,	449,	457,	461,	463	,467,	479	,487,	491	,499,	503,	509,	521	,523,	541
,547,	557,	563	,569,	571,	577,	587,	593,	599,	601,	607,	613,	617,	619,	631,	641,	643,	647	,653	,659
,661,	673,	677,	683,	691,	701,	709,	719,	727,	733,	739,	743,	751,	757,	761,	769,	773,	787	,797	,809
,811,	821,	823,	827,	829,	839,	853,	857,	859,	863,	877,	881,	883,	887,	907,	911,	919,	929	,937	,941
,947,	953	,967,	971,	977,	983,	991,	997 };

void solve() {
    ll n; cin >> n;
    vector<ll>ans;
    for (ll i = 0; i < primes.size(); i++)
    {
        if (primes[i] > n)
        {
            break;
        }
        for (ll j = primes[i]; j <= n; j *= primes[i])
        {
            ans.push_back(j);
        }
    }
    cout << ans.size() << endl;
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
