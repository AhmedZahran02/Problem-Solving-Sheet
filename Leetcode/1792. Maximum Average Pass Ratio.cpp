bool sortbyfirst(const pair<double, int> &a, const pair<double, int> &b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, int>> pq;
        // initialize
        for (int i = 0; i < classes.size(); i++)
        {
            pair<double, int> df;
            df.second = i;
            double difference = (double(classes[i][0] + 1) / (classes[i][1] + 1)) - (double(classes[i][0]) / classes[i][1]);
            df.first = difference;
            pq.push(df);
        }
        // pq
        while (extraStudents)
        {
            pair<double, int> df = pq.top();
            pq.pop();
            classes[df.second][0]++;
            classes[df.second][1]++;
            extraStudents--;
            double difference = (double(classes[df.second][0] + 1) / (classes[df.second][1] + 1)) - (double(classes[df.second][0]) / classes[df.second][1]);
            df.first = difference;
            pq.push(df);
        }
        // calculate answer
        double ans = 0;
        for (int i = 0; i < classes.size(); i++)
        {
            ans += double(classes[i][0]) / classes[i][1];
        }
        ans /= classes.size();
        return ans;
    }
};