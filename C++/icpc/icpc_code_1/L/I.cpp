#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;

const int kN = 1e5;

ll f[2][300][2][2][2];

int main()
{
    freopen("I.in", "r", stdin);
    memset(f, 0, sizeof f);
    ll n;
    cin >> n;
    std::string str;
    cin >> str;
    str = '0' + str;
    for (int i = 1; i <= n; ++i)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            memset(f[(i - 1) & 1][str[i]], 0, sizeof f[(i - 1) & 1][str[i]]);
            for (char j = '0'; j <= '9'; ++j)
            {
                if (str[i] == j)
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] = std::max({f[i & 1][str[i]][1][1][1], f[(i - 1) & 1][j][0][1][1], f[(i - 1) & 1][j][1][1][1]});
            }
            for (char j = 'a'; j <= 'z'; ++j)
            {
                if (str[i] == j)
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] = std::max({f[i & 1][str[i]][1][1][1], f[(i - 1) & 1][j][0][1][1], f[(i - 1) & 1][j][1][1][1]});
            }
            for (char j = 'A'; j <= 'Z'; ++j)
            {
                if (str[i] == j)
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] = std::max({f[i & 1][str[i]][1][1][1], f[(i - 1) & 1][j][0][1][1], f[(i - 1) & 1][j][1][1][1]});
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            memset(f[(i - 1) & 1][str[i]], 0, sizeof f[(i - 1) & 1][str[i]]);
            for (char j = '0'; j <= '9'; ++j)
            {
                if (str[i] == j)
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] = std::max({f[i & 1][str[i]][1][1][1], f[(i - 1) & 1][j][1][1][1], f[(i - 1) & 1][j][1][0][1]});
            }
            for (char j = 'a'; j <= 'z'; ++j)
            {
                if (str[i] == j)
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] = std::max({f[i & 1][str[i]][1][1][1], f[(i - 1) & 1][j][1][1][1], f[(i - 1) & 1][j][1][0][1]});
            }
            for (char j = 'A'; j <= 'Z'; ++j)
            {
                if (str[i] == j)
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] = std::max({f[i & 1][str[i]][1][1][1], f[(i - 1) & 1][j][1][1][1], f[(i - 1) & 1][j][1][0][1]});
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            for (char j = '0'; j <= '9'; ++j)
            {
                if (j == str[i])
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] += f[i - 1][j][1][1][1];
                f[i & 1][str[i]][1][1][1] %= 998244353;
                f[i & 1][str[i]][1][1][1] += f[i - 1][j][1][1][0];
                f[i & 1][str[i]][1][1][1] %= 998244353;
            }
            for (char j = 'a'; j <= 'z'; ++j)
            {
                if (j == str[i])
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] += f[i - 1][j][1][1][1];
                f[i & 1][str[i]][1][1][1] %= 998244353;
                f[i & 1][str[i]][1][1][1] += f[i - 1][j][1][1][0];
                f[i & 1][str[i]][1][1][1] %= 998244353;
            }
            for (char j = 'A'; j <= 'Z'; ++j)
            {
                if (j == str[i])
                {
                    continue;
                }
                f[i & 1][str[i]][1][1][1] += f[i - 1][j][1][1][1];
                f[i & 1][str[i]][1][1][1] %= 998244353;
                f[i & 1][str[i]][1][1][1] += f[i - 1][j][1][1][0];
                f[i & 1][str[i]][1][1][1] %= 998244353;
            }
            for (char j = '0'; j <= '9'; ++j)
            {
                if (j == toupper(str[i]))
                {
                    continue;
                }
                f[i & 1][toupper(str[i])][1][1][1] += f[i - 1][j][1][1][1];
                f[i & 1][toupper(str[i])][1][1][1] %= 998244353;
                f[i & 1][toupper(str[i])][1][1][1] += f[i - 1][j][1][1][0];
                f[i & 1][toupper(str[i])][1][1][1] %= 998244353;
            }
            for (char j = 'a'; j <= 'z'; ++j)
            {
                if (j == toupper(str[i]))
                {
                    continue;
                }
                f[i & 1][toupper(str[i])][1][1][1] += f[i - 1][j][1][1][1];
                f[i & 1][toupper(str[i])][1][1][1] %= 998244353;
                f[i & 1][toupper(str[i])][1][1][1] += f[i - 1][j][1][1][0];
                f[i & 1][toupper(str[i])][1][1][1] %= 998244353;
            }
            for (char j = 'A'; j <= 'Z'; ++j)
            {
                if (j == toupper(str[i]))
                {
                    continue;
                }
                f[i & 1][toupper(str[i])][1][1][1] += f[i - 1][j][1][1][1];
                f[i & 1][toupper(str[i])][1][1][1] %= 998244353;
                f[i & 1][toupper(str[i])][1][1][1] += f[i - 1][j][1][1][0];
                f[i & 1][toupper(str[i])][1][1][1] %= 998244353;
            }
        }
        else
        {
            for (char k = '0'; k <= '9'; ++k)
            {
                for (char j = '0'; j <= '9'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
                for (char j = 'a'; j <= 'z'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
                for (char j = 'A'; j <= 'Z'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
            }
            for (char k = 'a'; k <= 'z'; ++k)
            {
                for (char j = '0'; j <= '9'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
                for (char j = 'a'; j <= 'z'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
                for (char j = 'A'; j <= 'Z'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
            }
            for (char k = 'A'; k <= 'Z'; ++k)
            {
                for (char j = '0'; j <= '9'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
                for (char j = 'a'; j <= 'z'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
                for (char j = 'A'; j <= 'Z'; ++j)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    f[i & 1][k][1][1][1] += f[(i - 1) & 1][j][0][1][1] + f[(i - 1) & 1][j][1][1][1];
                    f[i & 1][k][1][1][1] %= 998244353;
                }
            }
        }
    }
    ll ans = 0;
    if ((str[n - 1] >= 'A' && str[n - 1] <= 'Z') || (str[n - 1] >= '0' && str[n - 1] <= '9'))
    {
        for (int i = 0; i < 300; ++i)
        {
            ans = std::max(ans, f[n - 1][i][1][1][1]);
            ans %= 998244353;
        }
    }
    else
    {
        for (int i = 0; i < 300; ++i)
        {
            ans += f[n - 1][i][1][1][1];
            ans %= 998244353;
        }
    }
    cout << ans;
    return 0;
}