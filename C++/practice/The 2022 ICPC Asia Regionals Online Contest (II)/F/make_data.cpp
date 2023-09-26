#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand() << 16) + (rand() << 1) + (rand() & 1);
}
int main(){
    freopen("F.in", "w", stdout);
    srand(GetTickCount());
    int T=brand()%10+1;
    printf("%d\n",T);
    while(T--){
        int t=brand()%10+1,u=brand()%10+1,v=brand()%10+1;
        printf("%d %d %d\n",t,u,v);
    }
    return 0;
}