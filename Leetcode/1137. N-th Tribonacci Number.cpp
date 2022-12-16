vector<int> ar(38, 0);
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1)
            return n;
        if (n == 2)return 1;
        if (ar[n] != 0) {
            return ar[n];
        }
        else {
            ar[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
            return ar[n];
        }
    }
};