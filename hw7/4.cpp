#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

string reorganizeString(string s) {
    int n = s.size();

    vector<int> count(26, 0);

    
    for (char c : s) {
        count[c - 'a']++;
    }

    
    int maxCount = 0;
    for (int x : count) {
        maxCount = max(maxCount, x);
    }

    if (maxCount > (n + 1) / 2) {
        return "";
    }

    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            pq.push({count[i], char('a' + i)});
        }
    }

    string result = "";

    while (pq.size() >= 2) {
        auto first = pq.top();
        pq.pop();

        auto second = pq.top();
        pq.pop();

        result += first.second;
        result += second.second;

        first.first--;
        second.first--;

        if (first.first > 0) {
            pq.push(first);
        }

        if (second.first > 0) {
            pq.push(second);
        }
    }

    
    if (!pq.empty()) {
        result += pq.top().second;
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    string ans = reorganizeString(s);

    if (ans == "") {
        cout << "\"\"" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}