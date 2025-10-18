// recursive

class Solution
{
public:
    long long recurse(int i, vector<int> &vals, unordered_map<int, long long> &freq, vector<long long> &dp)
    {
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        long long dmg = (long long)vals[i] * freq[vals[i]];

        // find most recent valid
        int j = i - 1;
        while (j >= 0 && vals[i] - vals[j] <= 2)
            j--;

        long long take = dmg + recurse(j, vals, freq, dp);
        long long skip = recurse(i - 1, vals, freq, dp);

        return dp[i] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int> &powers)
    {
        sort(powers.begin(), powers.end());

        unordered_map<int, long long> freq;
        for (int p : powers)
            freq[p]++;

        vector<int> vals;
        for (auto &p : freq)
            vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        vector<long long> dp(vals.size(), -1);
        return recurse((int)vals.size() - 1, vals, freq, dp);
    }
};

// itterative

class Solution
{
public:
    long long maximumTotalDamage(vector<int> &powers)
    {
        sort(powers.begin(), powers.end());

        // power value repetition
        unordered_map<int, long long> freq;
        for (int p : powers)
            freq[p]++;

        vector<long long> vals;
        for (auto p : freq)
            vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        vector<long long> dp(vals.size(), 0);

        dp[0] = vals[0] * freq[vals[0]];

        for (int i = 1; i < vals.size(); i++)
        {
            long long dmg = (long long)vals[i] * freq[vals[i]];

            // find latest suitable
            int j = upper_bound(vals.begin(), vals.begin() + i, vals[i] - 3) - vals.begin() - 1;
            if (j >= 0)
                dmg += dp[j];

            // take it or not
            dp[i] = max(dp[i - 1], dmg);
        }

        return dp[vals.size() - 1];
    }
};