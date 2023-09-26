#include <bits/stdc++.h>

typedef long long ll;

void Solve() {
    int n;
    scanf("%d", &n);
    std::vector<double> arr(n);
    for (int i = 0; i < n; ++i) {
        ll a,b;
        double p;
        scanf("%lld %lld %lf", &a, &b, &p);
        arr[i] = a*(1-p)+((a+b)*p);
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i < n; ++i) {
        arr[i] += arr[i-1];
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += arr[i];
    }
    printf("%.12lf\n", ans);
}

int main() {
    // freopen("a.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        Solve();
    }
    return 0;
}