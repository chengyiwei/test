#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int N,M,F[maxn],Q[maxn<<1],vis[maxn],hed,til,dep[maxn],fa[maxn];
vector<int> E[maxn];

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("E.in","r",stdin);
    freopen("E.out","w",stdout);
    N=read();M=read();
    dep[1]=1;
    for(int i=2;i<=N;i++)fa[i]=read(),dep[i]=dep[fa[i]]+1;
    for(int i=1;i<=M;i++){
        int a=read(),b=read();
        E[a].push_back(b);
        E[b].push_back(a);
    }
    vis[1]=1;Q[1]=1;til=1;
    while(hed!=til){
        ++hed;int v=Q[hed];
        int len=E[Q[hed]].size();
        for(int i=0;i<len;i++){
            int u=E[Q[hed]].at(i);
            int now_v=v,now_u=u;
            while(now_v!=now_u){
                if(vis[now_v]&&vis[now_u])break;
                if(vis[now_v]){
                    Q[++til]=now_u;F[now_u]=F[v]+1,vis[now_u]=1;
                    now_u=fa[now_u];
                }
                else {
                    Q[++til]=now_v;F[now_v]=F[v]+1,vis[now_v]=1;
                    now_v=fa[now_v];
                }
            }
        }
    }
    for(int i=2;i<=N;i++)printf("%d ",F[i]==0?-1:F[i]);
    return 0;
}