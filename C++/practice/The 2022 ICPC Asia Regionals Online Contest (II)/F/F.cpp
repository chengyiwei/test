#include<bits/stdc++
using namespace std;
typedef __int128_t LL;
inline LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();};
	while(ch<='9'&&ch>='0')ret=ret*10+ch-48,ch=getchar();
	return ret;
} 
inline void write(LL x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
LL K,X,Y,Max;
LL Top_len[105];
int posX,posY,T;
void init(LL P){
	Top_len[1]=1;
	for(int i=2;i;i++){
		Top_len[i]=Top_len[i-1]*(P+1);
		if(Max<=Top_len[i]){return ;}
	}
}
int main(){
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	T=read();
	while(T--){
		K=read();X=read();Y=read();
		Max=max(X,Y);
		init(K);
		for(int i=1;i;i++)if(Top_len[i]>=X){posX=i-1;break;}
		for(int i=1;i;i++)if(Top_len[i]>=Y){posY=i-1;break;}
		while(X!=Y){
			if(X>Y){
                X=(X-Top_len[posX]-1)/K+1;
                while(Top_len[posX]>=X)posX--;
            }
			else {
                Y=(Y-Top_len[posY]-1)/K+1,posY--;
                while(Top_len[posY]>=Y)posY--;
            }
		}
		write(X);putchar('\n');
	}
	return 0;
}