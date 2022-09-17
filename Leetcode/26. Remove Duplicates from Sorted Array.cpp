class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>ar;
        for (int i = 0; i < nums.size(); i++)
        {
            ar.insert(nums[i]);
        }
        int i = 0;
        for (auto itr : ar)
        {
            nums[i] = itr;
            i++;
        }
        return ar.size();
    }
};