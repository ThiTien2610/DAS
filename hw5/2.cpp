#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int norm(int x, int p) {
    x %= p;
    if (x < 0) x += p;
    return x;
}

int mod_pow(int a, int e, int p) {
    a = norm(a, p);

    if (e == 0)
        return 1;

    int res = mod_pow(a, e / 2, p);

    if (e % 2 == 1)
        return (long long)res * res % p * a % p;
    else
        return (long long)res * res % p;
}


int mod_inv(int a, int p) {
    // p is prime, a != 0
    return mod_pow(a, p - 2, p);
}

void trim(vector<int>& a) {
    while (!a.empty() && a.back() == 0) {
        a.pop_back();
    }
}

int degree(const vector<int>& a) {
    return (int)a.size() - 1;
}

void make_monic(vector<int>& a, int p) {
    trim(a);
    if (a.empty()) return;

    int inv_lead = mod_inv(a.back(), p);
    for (int& x : a) {
        x = (long long)x * inv_lead % p;
    }
}

vector<int> poly_mod(vector<int> a, const vector<int>& b, int p) {
    trim(a);
    vector<int> d = b;
    trim(d);

    if (d.empty()) {
        throw runtime_error("Division by zero polynomial");
    }

    while (!a.empty() && degree(a) >= degree(d)) {
        int shift = degree(a) - degree(d);
        int coef = (long long)a.back() * mod_inv(d.back(), p) % p;

        for (int i = 0; i < (int)d.size(); i++) {
            a[i + shift] = norm(a[i + shift] - (long long)coef * d[i], p);
        }

        trim(a);
    }

    return a;
}

vector<int> poly_gcd(vector<int> a, vector<int> b, int p) {
    trim(a);
    trim(b);

    while (!b.empty()) {
        vector<int> r = poly_mod(a, b, p);
        a = b;
        b = r;
    }

    make_monic(a, p);
    return a;
}

void print_poly(const vector<int>& a) {
    if (a.empty()) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i];
        if (i + 1 < (int)a.size()) cout << ' ';
    }
    cout << '\n';
}

int main() {
    int p;
    cin >> p;

    int n, m; // degrees
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 0; i <= n; i++) cin >> A[i];

    cin >> m;
    vector<int> B(m + 1);
    for (int i = 0; i <= m; i++) cin >> B[i];

    vector<int> g = poly_gcd(A, B, p);
    print_poly(g);

    return 0;
}