class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToGroup;
        vector<pair<int, string>> parents;

        auto find = [&] (int pos) {
            while (parents[pos].first != pos) {
                parents[pos].first = parents[parents[pos].first].first;
                pos = parents[pos].first;
            }
            return pos;
        };

        for (auto& account: accounts) {
            string& name = account[0];

            // find best(greatest) root
            optional<int> root;
            for (int i = 1; i < account.size(); i++) {
                const string& email = account[i];
                if (!emailToGroup.contains(email)) {
                    continue;
                }
                root = find(emailToGroup[email]);
            }
            if (!root) {
                root = parents.size();
                parents.push_back({*root, std::move(name)});
            }

            // assign new root to each email.
            for (int i = 1; i < account.size(); i++) {
                string& email = account[i];
                if (!emailToGroup.contains(email)) {
                    emailToGroup[email] = *root;
                    continue;
                }
                int currentRoot = find(emailToGroup[email]);
                parents[currentRoot].first = *root;
            }
        }

        unordered_map<int, vector<string>> rootToEmail;
        for (auto& [email, group]: emailToGroup) {
            int root = find(group);
            const string& name = parents[root].second;
            rootToEmail[root].push_back(std::move(email));
        }

        vector<vector<string>> result;
        for (auto& [root, emails] : rootToEmail) {
            vector<string> user;
            user.push_back(parents[root].second);
            user.insert(
                user.end(),
                make_move_iterator(emails.begin()),
                make_move_iterator(emails.end())
            );
            result.push_back(user);
        }
        return result;
    }
};














