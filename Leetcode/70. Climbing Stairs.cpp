vector<int> ar(46, -1);
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
        {
            return n;
        }
        if (ar[n] != -1) {
            return ar[n];
        }
        ar[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return ar[n];
    }
};