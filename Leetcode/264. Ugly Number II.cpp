typedef long long ll;
typedef unsigned long long ull;
#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector

ull fastpow(ull b, ull e) {
    if (!e)
    {
        return 1;
    }
    if (e & 1)
    {
        return b * fastpow(b, e - 1);
    }
    ull x = fastpow(b, e / 2);
    return x * x;
}

class Solution {
private:
    vector<ull> uglyNumbers;
public:
    Solution() {
        int i = 0, j = 0, k = 0;
        for (int i = 0; i <= 30; i++)
        {
            for (int j = 0; j <= 20; j++)
            {
                for (int k = 0; k <= 14; k++)
                {
                    ull value = fastpow(2, i) * fastpow(3, j) * fastpow(5, k);
                    uglyNumbers.push_back(value);
                }
            }
        }
        sortv(uglyNumbers);
    }
    int nthUglyNumber(int n) {
        return uglyNumbers[n - 1];
    }
};