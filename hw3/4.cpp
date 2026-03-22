#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(p.size());

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else if (p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    std::string s, p;

    std::cout << "Enter s: ";
    std::getline(std::cin, s);

    std::cout << "Enter p: ";
    std::getline(std::cin, p);

    Solution sol;
    bool result = sol.isMatch(s, p);

    if (result) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    return 0;
}