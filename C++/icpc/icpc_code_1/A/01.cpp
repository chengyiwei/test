#include <bits/stdc++.h>
using std::cin;
using std::cout;
int main() {
    // freopen("01.in","r",stdin);
    int n,m;
    cin >> n >> m;
    std::vector<std::string> a, b;
    std::set<std::string> aa,bb,tt;
    for (int i = 0; i < n; ++i) {
        std::string x;
        cin >> x;
        if (aa.count(x) == 0) {
            aa.insert(x);
            a.push_back(x);
        }
    }
    for (int i = 0; i < m; ++i) {
        std::string x;
        cin >> x;
        if (bb.count(x) == 0) {
            bb.insert(x);
            b.push_back(x);
        }
    }
    std::vector<std::string> ans;
    int i;
    for (i = 0; i < a.size() && i < b.size(); ++i) {
        std::string t = a[i];
        if (tt.count(t) == 0) {
            tt.insert(t);
            ans.push_back(t);
        }
        t = b[i];
        if (tt.count(t) == 0) {
            tt.insert(t);
            ans.push_back(t);
        }
    }
    for (int j = i; j < a.size(); ++j) {
        std::string t = a[j];
        if (tt.count(t) == 0) {
            tt.insert(t);
            ans.push_back(a[j]);
        }
    }
    for (int j = i; j < b.size(); ++j) {
        std::string t = b[j];
        if (tt.count(t) == 0) {
            tt.insert(t);
            ans.push_back(b[j]);
        }
    }
    for (auto x : ans) {
        cout << x << "\n";
    }
    return 0;
}