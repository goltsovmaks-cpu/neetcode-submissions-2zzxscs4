class Solution {
public:
    string simplifyPath(string path) {
        stack<string_view> breadCrumps;

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

            size_t len = (right == std::string::npos ? path.size() : right) - left;
            auto word = view.substr(left, len);
            if (".." == word) {
                if (!breadCrumps.empty()) {
                    breadCrumps.pop();
                }
            } else if ("." != word)  {
                breadCrumps.push(word);
            }
            left = right;
        }

        stack<string_view> reverseBreadCrumps;
        int lenght = 0;
        while (!breadCrumps.empty()) {
            reverseBreadCrumps.push(breadCrumps.top());
            lenght += breadCrumps.top().size() + 1;
            breadCrumps.pop();
        }

        string result;
        result.reserve(lenght);

        while (!reverseBreadCrumps.empty()) {
            result += "/";
            result += reverseBreadCrumps.top();
            reverseBreadCrumps.pop();
        }
        if (result.empty()) {
            return "/";
        }
        return result;
    }
};




