class Solution {
public:
    vector<int> sumZero(int n) {
        int value = n/2;
        vector<int> ans;
        for (int i = -value;i < 0;i++) ans.push_back(i);
        for (int i = 1;i <= value;i++) ans.push_back(i);
        if (n%2 == 1) ans.push_back(0);
        return ans;
    }
};