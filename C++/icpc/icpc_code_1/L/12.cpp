#include <bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;
int main() {
    // freopen("01.in","r",stdin);
    ll n, t;
    cin >> n >> t;
    std::vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    ll ans = ceil((double)arr.back() / t);
    cout << std::max(2ll, ans) << "\n";
    return 0;
}