#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=205;
int T,N,a[maxn];
LL F[maxn][2];
inline int read(){
    int ret = 0, f = 1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch=getchar();}
    while(ch>='0'&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return ret*f;
}
int main(){
    freopen("C.in","r",stdin);
    T=read();
    while(T--){
        N=read();
        for(int i=1;i<=N;i++)a[i]=read();
        F[1][0]=0;F[1][1]=0;
        for(int i=2;i<=N;i++){
            F[i][0]=F[i-1][1];
            F[i][1]=F[i-1][0];

            F[i][0]=max(F[i][0],F[i-1][0]+a[i]);
            F[i][1]=max(F[i][1],F[i][1]);
        }
        printf("%lld\n",max(F[N][0],F[N][1]));
    }
    return 0;
}