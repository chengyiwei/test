#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=505;
int N,T,posX[maxn],posY[maxn];
LL ans,a[maxn][maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline LL XX(){
    LL ret=0;
    for(int i=1;i<=N;i++)if(!posX[i]){
        LL min_=1<<30;
        for(int j=1;j<=N;j++) min_=min(min_,a[i][j]);
        ret+=min_;
    }
    return ret;
}
inline LL YY(){
    LL ret=0;
    for(int j=1;j<=N;j++)if(!posY[j]){
        LL min_=1<<30;
        for(int i=1;i<=N;i++) min_=min(min_,a[i][j]);
        ret+=min_;
    }
    return ret;
}
int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);

    T=read();
    while(T--){
        memset(posX,0,sizeof posX);
        memset(posY,0,sizeof posY);
        ans=0;
    
        N=read();
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){    
            a[i][j]=read();
            if(a[i][j]<=0){
                posX[i]=1;
                posY[j]=1;
                ans+=a[i][j];
            }
        }
        LL ans1=XX();
        LL ans2=YY();
        printf("%lld\n",ans+min(ans1,ans2));
    }
    return 0;
}