#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class MapSum {
private:
    struct Node {
        int sum;
        Node* child[26];

        Node() {
            sum = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;
    unordered_map<string, int> value;

public:
    MapSum() {
        root = new Node();
    }

    void insert(string key, int val) {
        int oldVal = 0;

        if (value.count(key)) {
            oldVal = value[key];
        }

        int delta = val - oldVal;
        value[key] = val;

        Node* cur = root;

        for (char c : key) {
            int id = c - 'a';

            if (cur->child[id] == nullptr) {
                cur->child[id] = new Node();
            }

            cur = cur->child[id];
            cur->sum += delta;
        }
    }

    int sum(string prefix) {
        Node* cur = root;

        for (char c : prefix) {
            int id = c - 'a';

            if (cur->child[id] == nullptr) {
                return 0;
            }

            cur = cur->child[id];
        }

        return cur->sum;
    }
};

int main() {
    MapSum mp;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            string key;
            int val;

            cin >> key >> val;

            mp.insert(key, val);
        } 
        else if (command == "sum") {
            string prefix;

            cin >> prefix;

            cout << mp.sum(prefix) << endl;
        }
    }

    return 0;
}