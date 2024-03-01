#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> factorials;

void precompute() {
    factorials.push_back(1);
    for (int i = 1; i <= 20; i++) {
        factorials.push_back(factorials.back() * i);
    }
}

void solve(int caseNum, ll n) {
    vector<int> used;
    for (int i = factorials.size() - 1; i >= 0; i--) {
        if (factorials[i] <= n) {
            n -= factorials[i];
            used.push_back(i);
        }
    }

    cout << "Case " << caseNum << ": ";
    if (n != 0) {
        cout << "impossible\n";
    } else {
        for (int i = used.size() - 1; i >= 0; i--) {
            cout << used[i] << "!";
            if (i != 0) cout << "+";
        }
        cout << "\n";
    }
}

int main() {
    precompute();

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll n;
        cin >> n;
        solve(t, n);
    }

    return 0;
}