#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> seats;

public:
    SeatManager(int n) {
        for (int i = 0; i < n; i++) {
            seats.push(i);
        }
    }

    int reserve() {
        int smallestSeat = seats.top();
        seats.pop();
        return smallestSeat;
    }

    void unreserve(int num) {
        seats.push(num);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    SeatManager manager(n);

    for (int i = 0; i < q; i++) {
        string operation;
        cin >> operation;

        if (operation == "reserve") {
            cout << manager.reserve() << endl;
        } 
        else if (operation == "unreserve") {
            int num;
            cin >> num;
            manager.unreserve(num);
        }
    }

    return 0;
}