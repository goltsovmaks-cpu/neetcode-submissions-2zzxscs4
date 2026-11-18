class Solution {
public:
    string encode(vector<string>& strs) {
        string result;

        for (auto& str: strs) {
            result += to_string(str.size()) + '\0' + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        string_view sv(s);

        vector<string> result;
        while (!sv.empty()) {
            size_t pos = sv.find('\0');
            size_t lenght = std::stoull(string(sv.substr(0, pos)));
            sv.remove_prefix(pos + 1);

            result.emplace_back(sv.begin(), sv.begin() + lenght);
            sv.remove_prefix(lenght);
        }

        return result;
    }
};
