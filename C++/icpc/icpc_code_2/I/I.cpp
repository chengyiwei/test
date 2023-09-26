#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
int jmp[maxn],T,N;
double p[maxn],F[maxn],ans;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("I.in","r",stdin);
    // freopen("I.out","w",stdout);
    T=read();
    while(T--){
        N=read();
        for(int i=0;i<N;i++)  jmp[i]=read();
        for(int i=0;i<N;i++)  p[i]=(double)read()/100000;
        ans=1<<30;
        for(int i=0;i<N;i++){
            double now=p[i];
            if(p[i]==0)continue;
            for(int j=1;j<=100;j++)
                now+=(p[i])*pow(1-p[i],j)*(i-jmp[i]+1)*(j)+(p[i])*pow(1-p[i],j);
            F[i]=now+i;
            ans=min(ans,F[i]);
        }
        printf("%.12lf\n",min(ans,(double)N));
    }
}