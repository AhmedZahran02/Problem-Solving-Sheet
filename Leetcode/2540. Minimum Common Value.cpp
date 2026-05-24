class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            int n1 = nums1[i];
            int n2 = nums2[j];
            if (n1 == n2)
                return n1;
            n2 > n1 ? i++ : j++;
        }
        return -1;
    }
};