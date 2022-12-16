vector<int> ar(31, 0);
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        if (ar[n] != 0) {
            return ar[n];
        }
        else {
            ar[n] = fib(n - 1) + fib(n - 2);
            return ar[n];
        }
    }
};