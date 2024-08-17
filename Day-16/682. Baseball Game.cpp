class Solution {
public:
    int calPoints(vector<string>& operations) {
         vector<int> ans;
        
        for (const auto& op : operations) {
            if (op == "+") {
                if (ans.size() >= 2) {
                    int num1 = ans[ans.size() - 2];
                    int num2 = ans[ans.size() - 1];
                    int sum = num1 + num2;
                    ans.push_back(sum);
                }
            } else if (op == "C") {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else if (op == "D") {
                if (!ans.empty()) {
                    int lastElement = ans.back();
                    int newElement = 2 * lastElement;
                    ans.push_back(newElement);
                }
            } else {
                ans.push_back(stoi(op)); 
            }
        }

        int total = 0;
        for (int score : ans) {
            total += score;
        }
        return total;
    }
};