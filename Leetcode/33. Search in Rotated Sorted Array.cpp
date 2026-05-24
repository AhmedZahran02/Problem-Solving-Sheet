class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        // O(n)
        while (i < j)
        {
            if (nums[j] < nums[i])
                j--;
            else
                break;
        }
        // O(log(n))
        int idx1 = lower_bound(nums.begin(), nums.begin() + j + 1, target) - nums.begin();
        int idx2 = lower_bound(nums.begin() + j + 1, nums.end(), target) - nums.begin();
        if (idx1 < nums.size() && target == nums[idx1])
            return idx1;
        if (idx2 < nums.size() && target == nums[idx2])
            return idx2;
        return -1;
    }
};