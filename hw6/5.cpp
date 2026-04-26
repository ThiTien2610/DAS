#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomMultiset {
private:
    vector<int> data;

    unordered_map<int, unordered_set<int>> pos;

public:
    RandomMultiset() {
        srand(time(0));
    }

    int Insert(int value) {
        data.push_back(value);

        int index = data.size() - 1;

        pos[value].insert(index);

        return pos[value].size();
    }

    int Delete(int value) {
        if (pos.find(value) == pos.end() || pos[value].empty()) {
            return -1;
        }

        int deleteIndex = *pos[value].begin();

        int lastIndex = data.size() - 1;
        int lastValue = data[lastIndex];

        pos[value].erase(deleteIndex);

        if (deleteIndex != lastIndex) {
            data[deleteIndex] = lastValue;

            pos[lastValue].erase(lastIndex);
            pos[lastValue].insert(deleteIndex);
        }

        data.pop_back();

        if (pos[value].empty()) {
            pos.erase(value);
            return 0;
        }

        return pos[value].size();
    }

    int GetRandom() {
        if (data.empty()) {
            return -1;
        }

        int index = rand() % data.size();

        return data[index];
    }
};


int main() {
    srand(time(0));

    RandomMultiset ms;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "Insert") {
            int value;
            cin >> value;
            cout << ms.Insert(value) << endl;
        }
        else if (command == "Delete") {
            int value;
            cin >> value;
            cout << ms.Delete(value) << endl;
        }
        else if (command == "GetRandom") {
            cout << ms.GetRandom() << endl;
        }
    }

    return 0;
}