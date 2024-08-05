// Longest String Chain

class Solution {
public:
    bool compare(const string& s1, const string& s2) {
        if (s1.size() != s2.size() + 1) return false;
        int first = 0, second = 0;
        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        return second == s2.size();
    }

    static bool comp(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (n == 0) return 0;

        sort(words.begin(), words.end(), comp);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; --index) {
            for (int prev = -1; prev < index; ++prev) {
                int len = dp[index + 1][prev + 1];
                if (prev == -1 || compare(words[index], words[prev])) {
                    len = max(len, 1 + dp[index + 1][index + 1]);
                }
                dp[index][prev + 1] = len;
            }
        }

        return dp[0][0];
    }
};