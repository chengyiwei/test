#include <bits/stdc++.h>

using std::cin;
using std::cout;

void Solve() {
    int n;
    cin >> n;
    std::vector<int> a(n);
    std::vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p[i] = x/(double)1e5;
    }
    std::vector<double> f(n);
    double ans = 1e9;
    for (int i = 0; i < n; ++i) {
    }
    cout << ans << "\n";
}

int main() {
    freopen("I.in","r",stdin);
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
}