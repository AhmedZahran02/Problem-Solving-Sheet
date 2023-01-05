////leet code
#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
typedef long long ll;
typedef unsigned long long ull;

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size() + 1, INT_MIN);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (dp[i - 1] >= 0)
            {
                dp[i] = dp[i - 1] + nums[i];
            }
            else {
                dp[i] = nums[i];
            }
        }
        sortv(dp);
        return dp[nums.size()];
    }
};