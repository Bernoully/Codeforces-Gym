#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	freopen("crypto.in","r",stdin);
		freopen("crypto.out","w",stdout);
     int a,b,n;
     int mx = 0,xx = 1,yy = 1,zz;
     cin >> n >> a >> b;
     for(int y = 1;y <= n;y++){
        int z ;
        for(int x = 2 ;(x-1) <= n;x*=2){
        	z = x-1;
        zz = ((a*z+b*y) ^ (a*y+b*z));
//      cout<<zz<<" "<<x-1<<" "<<y<<endl;
        	if(zz > mx&&z <= n&&y <= n&&(z&y) == y){
        		xx = z;
        		yy = y;
        		mx = zz;
        	}
        }
     }
     cout<<xx<<" "<<yy<<endl;
    return 0;
}
