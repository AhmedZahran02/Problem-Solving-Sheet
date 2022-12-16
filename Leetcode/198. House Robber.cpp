class Solution {
public:
    vector<int> ar;
    int getmax(vector<int>& nums, int index) {
        if (index >= nums.size())
        {
            return 0;
        }
        if (ar[index] != -1) {
            return ar[index];
        }
        int n1 = nums[index] + getmax(nums, index + 2);
        int n2 = 0 + getmax(nums, index + 1);
        ar[index] = max(n1, n2);
        return ar[index];
    }

    int rob(vector<int>& nums) {
        ar = vector<int>(101, -1);
        return max(getmax(nums, 0), getmax(nums, 1));
    }
};