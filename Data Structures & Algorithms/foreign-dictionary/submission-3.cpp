class Solution {
public:
    struct TNodeInfo{
        unordered_set<char> Children;
        int Parents = 0;
    };
    using TGraph = unordered_map<char, TNodeInfo>;

    string foreignDictionary(vector<string>& words) {
        TGraph graph;

        // just init somehow
        for (const string& word: words) {
            for (char ch: word) {
                graph[ch];
            }
        }

        for (int i = 1; i < words.size(); i++) {
            if (!buildRelation(words[i-1], words[i], graph)) {
                return "";
            }
        }

        queue<char> nodes;
        for (const auto& [node, info]: graph) {
            if (0 == info.Parents) {
                nodes.push(node);
            }
        }
    
        string result;
        while(!nodes.empty()) {
            char node = nodes.front();
            nodes.pop();
            result.push_back(node);

            for (char child: graph[node].Children) {
                graph[child].Parents--;
                if (0 == graph[child].Parents) {
                    nodes.push(child);
                }
            }
            graph.erase(node);
        }

        return graph.empty() ? result : "";
    }

    bool buildRelation(
        const string& lhs,
        const string& rhs,
        TGraph& graph)
    {
        int lenght = min(lhs.size(), rhs.size());
        for (int i = 0; i < lenght; i++) {
            char parent = lhs[i];
            char child = rhs[i];
            if (parent == child) {
                continue;
            }
            if (graph[parent].Children.insert(child).second) {
                graph[child].Parents++;
            }
            return true;
        }
        // abc, ab -> return false!
        return lhs.size() <= rhs.size();
    }
};
















