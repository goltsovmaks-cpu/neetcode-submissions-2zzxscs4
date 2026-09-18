class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, pair<int, bool>> personInfos;

        for (const auto& relation: trust) {
            personInfos[relation[0]].second = true;
            personInfos[relation[1]].first++;
        }

        const auto it = ranges::find_if(personInfos, [&] (const auto& item) {
            const auto& info = item.second;
            return info.first + 1 == personInfos.size() && !info.second;
        });
        return it == personInfos.end() ? -1 : it->first;
    }
};