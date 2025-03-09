// Made by AOZPROGRAMMING - All Rights Reserved :)

class Solution
{
public:
    long long factorial(long long n)
    {
        return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
    }

    long long countBadPairs(vector<int> &nums)
    {
        map<long long, long long> mp;
        for (long long i = 0; i < nums.size(); i++)
        {
            mp[nums[i] - i]++;
        }
        long long count = 0;
        for (auto i : mp)
        {
            if (i.second != 0)
            {
                count += ((i.second) * (i.second - 1)) / 2;
            }
        }
        long long total = ((nums.size()) * (nums.size() - 1)) / 2;
        return total - count;
    }
};