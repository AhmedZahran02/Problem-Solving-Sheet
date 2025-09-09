typedef long long ll;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        ll producingNow = 0;
        ll waitingProd = 0;
        queue<pair<int, ll>> production;
        queue<pair<int, ll>> forgetting;
        production.push({1 + delay, 1});
        waitingProd += 1;
        forgetting.push({1 + forget, 1});
        for (int i = 1; i <= n; i++)
        {
            while (production.front().first == i)
            {
                producingNow += (production.front().second % ll(1e9 + 7));
                producingNow %= ll(1e9 + 7);
                waitingProd -= (production.front().second % ll(1e9 + 7));
                waitingProd += ll(1e9 + 7);
                waitingProd %= ll(1e9 + 7);
                production.pop();
            }
            while (forgetting.front().first == i)
            {
                producingNow -= ((forgetting.front().second) % ll(1e9 + 7));
                producingNow += ll(1e9 + 7);
                producingNow %= ll(1e9 + 7);
                forgetting.pop();
            }
            if (producingNow)
            {
                producingNow %= ll(1e9 + 7);
                production.push({i + delay, producingNow});
                waitingProd += producingNow % ll(1e9 + 7);
                waitingProd %= ll(1e9 + 7);
                forgetting.push({i + forget, producingNow});
            }
        }
        return (waitingProd % ll(1e9 + 7) + producingNow % ll(1e9 + 7)) % ll(1e9 + 7);
    }
};