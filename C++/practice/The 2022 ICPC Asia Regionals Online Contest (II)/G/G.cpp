#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
typedef long long LL;
LL TT=1e9+7;
int N,M,tot;
LL F[maxn];
struct G{
    int l,r,pst,fa;
    vector <int> son;
    bool operator <(const G &B)const  {return l<B.l||(l==B.l&&r>B.r);}
}a[maxn];
inline LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();};
	while(ch<='9'&&ch>='0')ret=ret*10+ch-48,ch=getchar();
	return ret;
} 
LL Fac[maxn];
int st[maxn],top,lst;
LL dfs(int x){
    int len=a[x].son.size();
    LL ret=1;
    for(int i=0;i<len;i++)ret=(ret*dfs(a[x].son[i]))%TT;
    ret=(ret*Fac[len])%TT;
    return ret;
}
int main(){
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
    N=read();M=read();
    for(int i=1;i<=M;i++){
        int l=read(),r=read();
        if(l==r||(l==1&&r==N))continue;
        tot++;
        a[tot].l=l,a[tot].r=r;
    }
    for(int i=1;i<=N;i++){
        tot++;
        a[tot].l=i;a[tot].r=i;a[tot].pst=1;
    }
    ++tot;a[tot].l=1,a[tot].r=N;
    sort(a+1,a+1+tot);
    Fac[0]=1;
    for(int i=1;i<=tot;i++){
        F[i]=1;
        Fac[i]=(Fac[i-1]*(LL)i)%TT;
    }
    st[++top]=1;
    for(int i=2;i<=tot;i++){
        if(top!=0&&a[st[top]].r<a[i].l){
            while(a[st[top]].r<a[i].l) top--;
            a[i].fa=st[top],a[st[top]].son.push_back(i);
        }
        else{ 
            a[i].fa=st[top],a[st[top]].son.push_back(i);
        }
        st[++top]=i;
    }
    printf("%lld\n",dfs(1));
    return 0;
}