class Solution {
public:


    void findmin(vector<int>& ar, vector<int>& dp, int i) {
        if (i < 0) return;

        for (int j = i; j < ar.size(); j++) {
            if (ar[j] > ar[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        findmin(ar, dp, --i);
    }

    int lengthOfLIS(vector<int>& nums) {
        int maxsize = 1;
        vector<int> dp(nums.size(), 1);
        findmin(nums, dp, nums.size() - 1);
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > maxsize) {
                maxsize = dp[i];
            }
        }
        return maxsize;
    }
};