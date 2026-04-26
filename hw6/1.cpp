#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> morse = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    set<string> unique_codes;

    for (string word : words) {
        string code = "";

        for (char c : word) {
            int index = c - 'a';
            code += morse[index];
        }

        unique_codes.insert(code);
    }

    return unique_codes.size();
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << uniqueMorseRepresentations(words) << endl;

    return 0;
}