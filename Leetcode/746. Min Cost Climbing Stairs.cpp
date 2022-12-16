class Solution {
public:
    vector<int>ar;
    int minCostClimbingStairs(const vector<int>& cost) {
        ar = vector<int>(1001, -1);
        return min(getmin(cost, 0), getmin(cost, 1));
    }

    int getmin(const vector<int>& cost, int index) {
        if (index + 2 > (int)(cost.size() - 1))
        {
            return cost[index];
        }
        if (ar[index] != -1) {
            return ar[index];
        }
        ar[index] = cost[index] + min(getmin(cost, index + 1), getmin(cost, index + 2));
        return ar[index];
    }
};