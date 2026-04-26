#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> count(26, 0);

    
    for (char c : magazine) {
        count[c - 'a']++;
    }

    
    for (char c : ransomNote) {
        count[c - 'a']--;

        if (count[c - 'a'] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string ransomNote, magazine;

    cin >> ransomNote >> magazine;

    if (canConstruct(ransomNote, magazine)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}