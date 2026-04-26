#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2) return n;

        int answer = 1;

        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> slopes;

            int samePoint = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    samePoint++;
                    continue;
                }

                int g = gcd(dx, dy);

                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                if (dx == 0) {
                    dy = 1;
                }

                if (dy == 0) {
                    dx = 1;
                }

                slopes.push_back({dy, dx});
            }

            sort(slopes.begin(), slopes.end());

            int best = 0;
            int count = 1;

            for (int k = 0; k < slopes.size(); k++) {
                if (k > 0 && slopes[k] == slopes[k - 1]) {
                    count++;
                } else {
                    count = 1;
                }

                best = max(best, count);
            }

            answer = max(answer, best + samePoint + 1);
        }

        return answer;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution sol;
    cout << sol.maxPoints(points) << endl;

    return 0;
}