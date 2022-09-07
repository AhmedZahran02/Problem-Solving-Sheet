void mergeArrays(vector<int> arr1, vector<int> arr2, int n1,
    int n2, vector<int>& arr3)
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < n1)
        arr3[k++] = arr1[i++];

    while (j < n2)
        arr3[k++] = arr2[j++];
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    vector<int> nums3(nums1.size()+nums2.size());
    mergeArrays(nums1, nums2, nums1.size(), nums2.size(), nums3);
    int size3 = nums3.size();
    if (size3%2==0)
    {
        return (nums3[size3 / 2 -1] + nums3[size3 / 2]) / 2.0;
    }
    else
    {
        return nums3[size3 / 2];
    }
}
};