class Solution {
public:
    bool check(vector<int>& nums) {
        int broken = 0;
        for (int i = 0; i < nums.size(); i++){
            if(nums[(i+1)%nums.size()] < nums[i]) broken++;
            if (broken > 1) return false;
        }
        return broken <= 1;
    }
};