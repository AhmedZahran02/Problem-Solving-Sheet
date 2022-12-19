class disjointset {
private:
    int size;
    int* sz;
    int* id;
    int numofcomp;

public:
    disjointset(int size) {
        if (size > 0)
        {
            this->size = size;
            this->numofcomp = size;
            sz = new int[size];
            id = new int[size];

            for (int i = 0; i < size; i++)
            {
                id[i] = i;
                sz[i] = 1;
            }
        }
        else {
            this->size = 0;
            this->numofcomp = 0;
            sz = new int[0];
            id = new int[0];
        }
    }

    int find(int p) {
        int trav = p;
        while (trav != id[trav])
        {
            trav = id[trav];
        }

        while (p != trav) {
            int next = id[p];
            id[p] = trav;
            p = next;
        }

        return trav;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int componentsize(int p) {
        return sz[find(p)];
    }

    int getsize() {
        return size;
    }

    int getnumofcomponents() {
        return numofcomp;
    }

    void unify(int p, int q) {
        int root1 = find(p);
        int root2 = find(q);

        if (root1 == root2)
        {
            return;
        }

        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
        else {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        numofcomp--;
    }
};

//leet code
#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
typedef long long ll;
typedef unsigned long long ull;

class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>>edges;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {

                edges.push_back({ abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),{i,j} });
            }
        }
        sortv(edges);
        disjointset dj(points.size());
        int cnt = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            if (dj.find(edges[i].second.first) != dj.find(edges[i].second.second))
            {
                dj.unify(edges[i].second.first, edges[i].second.second);
                cnt += edges[i].first;
            }
        }
        return cnt;
    }
};