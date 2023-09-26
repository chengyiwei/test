#include<bits/stdc++.h>
using namespace std;
int N,T,a[105],b[105];
inline int read(){
    int ret = 0, f = 1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch=getchar();}
    while(ch>='0'&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return ret*f;
}
int main(){
    // freopen("A.in","r",stdin);
    T=read();
    while(T--){
        N=read();
        for(int i=1;i<=N;i++) a[i]=read();
        b[1]=1;
        for(int i=1;i<=N;i++){
            if(b[i]==a[i])b[i]++;
            b[i+1]=b[i]+1;
        }
        printf("%d\n",b[N]);
    }
    return 0;
}