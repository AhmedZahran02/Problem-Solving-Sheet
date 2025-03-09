// Made by AOZPROGRAMMING - All Rights Reserved :)

class ProductOfNumbers
{
private:
    vector<int> ar;
    int zeroIndex;

public:
    ProductOfNumbers()
    {
        ar.push_back(1);
        zeroIndex = -1;
    }

    void add(int num)
    {
        if (num == 0)
            zeroIndex = ar.size();
        ar.push_back(num * (ar[ar.size() - 1] == 0 ? 1 : ar[ar.size() - 1]));
    }

    int getProduct(int k)
    {
        if (((int)(ar.size()) - k - 1) < zeroIndex)
            return 0;
        return ar[ar.size() - 1] / (ar[ar.size() - k - 1] == 0 ? 1 : ar[ar.size() - k - 1]);
    }
};