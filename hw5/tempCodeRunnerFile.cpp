#include <iostream>
#include <vector>
using namespace std;


bool isPrime(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    }
    return true;
}


int largestPrimeLessThan(int limit) {
    for (int x = limit - 1; x >= 2; x--) {
        if (isPrime(x)) return x;
    }
    return 0; 
}

bool primeSubOperation(vector<int>& nums) {
    int prev = 0;

    for (int i = 0; i < nums.size(); i++) {
        int limit = nums[i] - prev;

        // muốn chọn p lớn nhất sao cho p < limit
        int p = largestPrimeLessThan(limit);

        nums[i] -= p;

        if (nums[i] <= prev) {
            return false;
        }

        prev = nums[i];
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (primeSubOperation(nums)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}