#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N,M;
LL ans;
const int maxn=1e6+5,maxe=2e6+5;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret;
}
struct AS{
    LL hsh,sum_du;
    bool operator <(const AS B)const {return hsh<B.hsh;}
}a[maxn];
int tot,id[maxn];
int cnt,nxt[maxe],son[maxe],lnk[maxn],vis[maxn],du[maxn],fa[maxn];
inline void add_e(int x,int y){son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;du[x]++;}
int put[maxn],flg=0;
LL hsh[maxn];
void dfs(int x,int father){
    LL ret=0;
    fa[x]=father;
    vis[x]=1;
    for(int j=lnk[x];j;j=nxt[j]){
        if(vis[son[j]]==0) {
            dfs(son[j],father);
        }
    }
}
int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    N=read();M=read();
    for(int i=1;i<=M;i++){
        int x=read(),y=read();
        add_e(x,y);add_e(y,x);
    }
    for(int i=1;i<=N;i++){
        if(vis[i])continue;
        dfs(i,i);
    }
    for(int i=1;i<=N;i++){
        if(fa[i]==i){
            id[i]=++tot;
        }
    }
    for(int i=1;i<=N;i++){
        a[id[fa[i]]].sum_du+=du[i];
        a[id[fa[i]]].hsh++;
    }
    for(int i=1;i<=tot;i++){
        if(a[i].hsh*(a[i].hsh-1)!=a[i].sum_du)flg=1;
    }
    if(flg==1){
        for(int i=1;i<=tot;i++)
            ans+=(a[i].hsh*(a[i].hsh-1)-a[i].sum_du)/2;
    }
    else {
        sort(a+1,a+1+tot);
        ans=a[1].hsh*a[2].hsh;
    }
    printf("%lld\n",ans);
    return 0;
}