class Solution {
public:
    string simplifyPath(string path) {

        vector<string_view> breadCrumps;

        auto view = std::string_view(path);

        size_t left = 0;
        size_t right = 0;

        while (left < view.size()) {

            while (left < view.size() && '/' == view[left]) {
                left++;
            }

            if (view.size() == left) {
                break;
            }

            right = view.find('/', left);
            size_t len = min(right, view.size()) - left;
            auto word = view.substr(left, len);

            if (".." == word) {
                if (!breadCrumps.empty()) {
                    breadCrumps.pop_back();
                }
            } else if ("." != word)  {
                breadCrumps.push_back(std::move(word));
            }
            left = right;
        }

        if (breadCrumps.empty()) {
            return "/";
        }

        string result;
        result.reserve(path.size());
        for (auto& view: breadCrumps) {
            result += "/";
            result += view;
        }

        return result;
    }
};




