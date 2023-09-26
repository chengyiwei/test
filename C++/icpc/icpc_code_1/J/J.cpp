#include<bits/stdc++.h>
using namespace std;
struct ctr{
    double x,y,r;
}C1,C2;
int T;
const double sq2=sqrt(2);
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("j.in","r",stdin);
    freopen("j.out","w",stdout);
    T=read();
    double x_1,x_2,y_1,y_2,posx,posy,ans1,ans2,ans3,ans4,ans5,ans6,ans;
    while(T--){
        cin>>x_1>>y_1>>x_2>>y_2;
        C1.x=(x_1+x_2)/2;C1.y=(y_1+y_2)/2;C1.r=sqrt((x_1-C1.x)*(x_1-C1.x)+(y_1-C1.y)*(y_1-C1.y));
        cin>>x_1>>y_1>>x_2>>y_2;
        C2.x=(x_1+x_2)/2;C2.y=(y_1+y_2)/2;C2.r=sqrt((x_1-C2.x)*(x_1-C2.x)+(y_1-C2.y)*(y_1-C2.y));
        
        posx=C2.x-C2.r/sq2,posy=C2.y-C2.r/sq2;
        ans1=(abs(posx-C1.x)+abs(posy-C1.y));

        posx=C2.x+C2.r/sq2,posy=C2.y-C2.r/sq2;
        ans2=(abs(posx-C1.x)+abs(posy-C1.y));
        
        posx=C2.x-C2.r/sq2,posy=C2.y+C2.r/sq2;
        ans3=(abs(posx-C1.x)+abs(posy-C1.y));
        
        posx=C2.x+C2.r/sq2,posy=C2.y+C2.r/sq2;
        ans4=(abs(posx-C1.x)+abs(posy-C1.y));
        
        ans=min(min(ans1,ans2),min(ans3,ans4));
        if(C2.x-C2.r<=C1.x&&C2.x+C2.r>=C1.x){
            ans5=abs(C1.y-C2.y)-sqrt(C2.r*C2.r-(C2.x-C1.x)*(C2.x-C1.x));
            ans=min(ans,ans5);
        }
        if(C2.y-C2.r<=C1.y&&C2.y+C2.r>=C1.y){
            ans6=abs(C1.x-C2.x)-sqrt(C2.r*C2.r-(C2.y-C1.y)*(C2.y-C1.y));
            ans=min(ans,ans6);
        }
            
        printf("%.10lf\n",ans);
    }
    return 0;
}