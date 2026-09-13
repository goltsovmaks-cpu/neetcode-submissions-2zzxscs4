class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> projects; // capital, profite
        projects.reserve(profits.size());
        for (int i = 0; i < capital.size(); i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        ranges::sort(projects);

        int idx = 0;
        int projectsLeft = k;
        int currentCapital = w;
        priority_queue<int> queue;
        
        while (projectsLeft > 0) { //????
            // first add candidates
            while (idx < projects.size() && projects[idx].first <= currentCapital) {
                queue.push(projects[idx].second);
                idx++;
            }
            // then pick up best candidate
            if (queue.empty()) {
                break;
            }

            currentCapital += queue.top();
            queue.pop();
            projectsLeft--;
        }
        return currentCapital;

    }
};