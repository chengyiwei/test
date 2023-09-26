#include<bits/stdc++.h>
using namespace std;
int T,N;
int a[55][55],max_x,num,min_x,ans,now_num;
int hsh_x[55],hsh_vis[55];
vector<int> hsh[55];
inline int read(){
    int ret = 0, f = 1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch=getchar();}
    while(ch>='0'&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return ret*f;
}
void pick(int x){
    for(int j=1;j<=a[x][0];j++){
        hsh_x[a[x][j]]--;
        if(hsh_x[a[x][j]]==0) now_num--;
    }
}
int main(){
    // freopen("B.in","r",stdin);
    // freopen("B.out","w",stdout);
    T=read();
    while(T--){
        max_x=0;num=0;min_x=1<<30;ans=0;
        memset(hsh,0,sizeof hsh);
        N=read();
        for(int i=1;i<=N;i++){
            a[i][0]=read();
            for(int j=1;j<=a[i][0];j++){
                a[i][j]=read(),max_x=max(max_x,a[i][j]),min_x=min(min_x,a[i][j]);
                hsh[a[i][j]].push_back(i);
            }
        }
        for(int i=min_x;i<=max_x;i++){
            hsh_vis[i]=hsh_x[i]=hsh[i].size();
            if(hsh_x[i]>0) num++;
        }
        for(int i=min_x;i<=max_x;i++){
            now_num=num;
            int siz=hsh_x[i];
            if(siz==0)continue;
            for(int j=0;j<siz;j++){
                pick(hsh[i][j]);
            }
            ans=max(ans,now_num);
            for(int j=min_x;j<=max_x;j++)hsh_x[j]=hsh_vis[j];
        }
        printf("%d\n",ans);
    }
    return 0;
}