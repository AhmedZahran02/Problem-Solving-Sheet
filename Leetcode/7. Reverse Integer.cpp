class Solution {
public:
    int reverse(int x) {
    string s = to_string(x);
    std::reverse(s.begin(), s.end());
    long long ans = stoll(s);
        if(x<0){
            ans=-ans;
        }
    if (ans > pow(2, 31) - 1 || ans < -pow(2, 31))
    {
        ans = 0;
    }
    return ans;
}
};