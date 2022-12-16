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
        int n1 = getmax(nums, 1);
        ar = vector<int>(101, -1);
        vector<int>ar2 = nums;
        if (nums.size() > 1) {
            ar2.pop_back();
        }
        int n2 = getmax(ar2, 0);
        return max(n1, n2);
    }
};