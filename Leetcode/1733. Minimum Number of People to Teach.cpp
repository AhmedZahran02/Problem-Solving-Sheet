class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        vector<set<int>> knows(m);
        for (int i = 0; i < m; i++) {
            knows[i] = set<int>(languages[i].begin(), languages[i].end());
        }

        unordered_set<int> needTeach;
        for (auto& f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            bool canComm = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    canComm = true;
                    break;
                }
            }
            if (!canComm) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        if (needTeach.empty()) return 0;

        int best = 0;
        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (int person : needTeach) {
                if (knows[person].count(lang)) cnt++;
            }
            best = max(best, cnt);
        }

        return (int)needTeach.size() - best;
    }
};
