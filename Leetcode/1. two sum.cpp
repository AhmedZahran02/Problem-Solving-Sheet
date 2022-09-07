class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int>mp;
    vector<int> ar(2);
    for (int i = 0; i < nums.size(); i++) {
        if (mp[nums[i]]!=0 && target==2* nums[i])
        {
            ar[0] = i;
            ar[1] = mp[target - nums[i]] - 1;
            break;
        }
        mp[nums[i]] = i+1;
        if (mp[target - nums[i]] != 0 && mp[target - nums[i]]!=i+1) {
            ar[0] = i;
            ar[1] = mp[target - nums[i]]-1;
            break;
        }
    }
    return ar;
}
};