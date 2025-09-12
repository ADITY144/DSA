class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = 0;
        for (auto& l : languages)
            for (int lang : l)
                m = max(m, lang); // max language number

        unordered_map<int, unordered_set<int>> userLang;
        for (int i = 0; i < languages.size(); ++i)
            for (int lang : languages[i])
                userLang[i + 1].insert(lang);

        unordered_set<int> needTeach;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : userLang[u]) {
                if (userLang[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        int res = INT_MAX;
        for (int lang = 1; lang <= m; ++lang) {
            int count = 0;
            for (int user : needTeach) {
                if (!userLang[user].count(lang))
                    count++;
            }
            res = min(res, count);
        }

        return res;
    }
};