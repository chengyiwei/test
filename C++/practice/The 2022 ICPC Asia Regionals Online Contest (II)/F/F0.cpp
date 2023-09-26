#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll INF = 0x3f3f3f3f;
ll Tex=1, k, a, b;
void AC()
{
	cin >> k >> a >> b;
    while(a != b)
    {
    	ll y, p = 1, t = 0, l, r, c, kl, kr;
    	if(a > b)
    	{
    		c = a;
    		while(p < c) p *= (k+1);
    		p /= (k+1);
    		r = (c - p - 1) / k + 1;
    		l = (c - p) / k;
    		while(l <= r)
    		{
    			y = l;
    			kl = p + (y - 1) * k + 1;
    			kr = p + y * k;
    			if(kl <= c && c <= kr) break;
    			l ++;
			}
			a = y;
		}
		else
		{
			c = b;
    		while(p < c) p *= (k+1);
    		p /= (k+1);
    		r = (c - p - 1) / k + 1;
    		l = (c - p) / k;
    		while(l <= r)
    		{
    			y = l;
    			kl = p + (y - 1) * k + 1;
    			kr = p + y * k;
    			if(kl <= c && c <= kr) break;
    			l ++;
			}
			b = y;
		}
		
	}
//	print(l);putchar(' ');print(r);putchar('\n');
	cout << a << endl;
}
int main()
{
    freopen("F.in","r",stdin);
    freopen("F0.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> Tex;
	while(Tex--) AC();
	return 0;
}