// Made by AOZPROGRAMMING - All Rights Reserved :)

#include <bits/stdc++.h>

class disjointset
{
private:
    int size;
    int *sz;
    int *id;
    int numofcomp;

public:
    disjointset(int size)
    {
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
        else
        {
            this->size = 0;
            this->numofcomp = 0;
            sz = new int[0];
            id = new int[0];
        }
    }

    int find(int p)
    {
        int trav = p;
        while (trav != id[trav])
        {
            trav = id[trav];
        }

        while (p != trav)
        {
            int next = id[p];
            id[p] = trav;
            p = next;
        }

        return trav;
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    void setValue(int id, int val)
    {
        sz[id] = val;
    }

    int componentsize(int p)
    {
        return sz[find(p)];
    }

    int getsize()
    {
        return size;
    }

    int getnumofcomponents()
    {
        return numofcomp;
    }

    void unify(int p, int q)
    {
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
        else
        {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        numofcomp--;
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        disjointset ds = disjointset(grid.size() * grid[0].size());
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                // check if 0
                if (grid[i][j] == 0)
                    continue;
                // check up
                if (i - 1 >= 0 && grid[i - 1][j])
                    ds.unify(i * (grid[i].size()) + j, (i - 1) * (grid[i].size()) + j);
                // check down
                if (i + 1 < grid.size() && grid[i + 1][j])
                    ds.unify(i * (grid[i].size()) + j, (i + 1) * (grid[i].size()) + j);
                // check right
                if (j + 1 < grid[i].size() && grid[i][j + 1])
                    ds.unify(i * (grid[i].size()) + j, i * (grid[i].size()) + (j + 1));
                // check left
                if (j - 1 >= 0 && grid[i][j - 1])
                    ds.unify(i * (grid[i].size()) + j, i * (grid[i].size()) + (j - 1));
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (!grid[i][j])
                {
                    int val = 0;
                    map<int, bool> mp;
                    // check up
                    if (i - 1 >= 0 && grid[i - 1][j] && !mp[ds.find((i - 1) * (grid[i].size()) + j)])
                    {
                        val += ds.componentsize((i - 1) * (grid[i].size()) + j);
                        mp[ds.find((i - 1) * (grid[i].size()) + j)] = 1;
                    }
                    // check down
                    if (i + 1 < grid.size() && grid[i + 1][j] && !mp[ds.find((i + 1) * (grid[i].size()) + j)])
                    {
                        val += ds.componentsize((i + 1) * (grid[i].size()) + j);
                        mp[ds.find((i + 1) * (grid[i].size()) + j)] = 1;
                    }
                    // check right
                    if (j + 1 < grid[i].size() && grid[i][j + 1] && !mp[ds.find(i * (grid[i].size()) + j + 1)])
                    {
                        val += ds.componentsize(i * (grid[i].size()) + j + 1);
                        mp[ds.find(i * (grid[i].size()) + j + 1)] = 1;
                    }
                    // check left
                    if (j - 1 >= 0 && grid[i][j - 1] && !mp[ds.find(i * (grid[i].size()) + j - 1)])
                    {
                        val += ds.componentsize(i * (grid[i].size()) + j - 1);
                        mp[ds.find(i * (grid[i].size()) + j - 1)] = 1;
                    }
                    ans = max(ans, val + 1);
                }
            }
        }
        if (ans == INT_MIN)
            return ds.componentsize(0);
        return ans;
    }
};