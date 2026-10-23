class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<bool> banned(senate.size());
        vector<pair<int, int>> teams(2, {0, 0});

        for (char s: senate) {
            if ('R'== s) {
                teams[0].second++;
            } else {
                teams[1].second++;
            }
        }

        while (teams[0].second > 0 && teams[1].second > 0) {
            for (int i = 0; i < senate.size(); i++) {
                if (banned[i]) {
                    continue;
                }

                int idx = 'R' == senate[i] ? 0 : 1;
                if (teams[idx].first > 0) { // we have been banned :(
                    banned[i] = true;
                    teams[idx].first--;
                    teams[idx].second--;
                } else { //HEHE
                    int oppositeTeam = (idx + 1) % teams.size();
                    teams[oppositeTeam].first++;
                }
            }
        }
        
        return teams[0].second > 0 ? "Radiant" : "Dire";
    }
};