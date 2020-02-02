class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score = 0;
        std::vector<int> rounds;
        int pts = 0;
        for (auto &op : ops) {
            if (op == "+") {
                pts = rounds[rounds.size()-1] + rounds[rounds.size()-2];
                rounds.push_back(pts);
                score += pts;
            }
            else if (op == "D") {
                pts = 2 * rounds[rounds.size()-1];
                rounds.push_back(pts);
                score += pts;
            }
            else if (op == "C") {
                score -= rounds[rounds.size()-1];
                rounds.pop_back();
            }
            else {
                pts = std::stoi(op);
                rounds.push_back(pts);
                score += pts;
            }
        }
        return score;
    }
};
