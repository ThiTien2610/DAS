#include <iostream>
#include <algorithm>

using namespace std;

static const int P = 4567;


int inv_table[P];

bool has_sqrt[P];

int sqrt1_table[P];
int sqrt2_table[P];

int norm(long long x) {
    x %= P;
    if (x < 0) x += P;
    return (int)x;
}

void init_tables() {
    // 1) 
    inv_table[1] = 1;
    for (int i = 2; i < P; ++i) {
        inv_table[i] = P - (long long)(P / i) * inv_table[P % i] % P;
    }

    // 2) 
    for (int i = 0; i < P; ++i) {
        has_sqrt[i] = false;
        sqrt1_table[i] = -1;
        sqrt2_table[i] = -1;
    }

    // 3) Store x^2 mod P
    for (int x = 0; x < P; ++x) {
        int s = (long long)x * x % P;
        if (!has_sqrt[s]) {
            has_sqrt[s] = true;
            sqrt1_table[s] = x;
            sqrt2_table[s] = x;
        } else if (x != sqrt1_table[s]) {
            sqrt2_table[s] = x;
        }
    }
}

struct Answer {
    int type;// type = 0 "No solution", type = 1 "One solution", = 2 "Two solutions", =3 "Multiple solutions"
    int x1, x2;
};

Answer solve_quadratic(int a, int b, int c) {
    a = norm(a);
    b = norm(b);
    c = norm(c);

    // ax^2 + bx + c, if a = 0 
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return {3, 0, 0};
            } else {
                return {0, 0, 0};
            }
        }

        int x = (long long)norm(-c) * inv_table[b] % P;
        return {1, x, x};
    }

    // delta = b^2 - 4ac mod P
    int delta = norm((long long)b * b - 4LL * a * c);

    if (!has_sqrt[delta]) {
        return {0, 0, 0};
    }

    int two_a = norm(2LL * a);
    int inv_two_a = inv_table[two_a];

    int r1 = sqrt1_table[delta];
    int r2 = sqrt2_table[delta];

    int x1 = (long long)norm(-b + r1) * inv_two_a % P;
    int x2 = (long long)norm(-b + r2) * inv_two_a % P;

    if (x1 == x2) {
        return {1, x1, x1};
    }

    if (x1 > x2) swap(x1, x2);
    return {2, x1, x2};
}

int main() {
    init_tables();

    int a, b, c;
    cin >> a >> b >> c;

    Answer ans = solve_quadratic(a, b, c);

    if (ans.type == 0) {
        cout << "No solution\n";
    } else if (ans.type == 1) {
        cout << "One solution\n";
        cout << ans.x1 << "\n";
    } else if (ans.type == 2) {
        cout << "Two solutions\n";
        cout << ans.x1 << " " << ans.x2 << "\n";
    } else {
        cout << "Multiple solutions\n";
    }

    return 0;
}