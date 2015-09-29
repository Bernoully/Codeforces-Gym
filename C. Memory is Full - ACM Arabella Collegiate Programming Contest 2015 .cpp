#include <iostream>
#include <algorithm>
using namespace std;
int main(){
int k,m,n;
int tc;
cin >> tc;
while(tc--){
int a[1000];
cin >> k >> m >> n;
for(int i = 0;i < n ;i++) cin >> a[i];
sort(a,a+ n);
int cs = k - m;
int c = 0;
for(int i = 0;i < n;i++)
    if(cs >= a[i] )
    c++,cs-=a[i];
cout<<n-c<<endl;
}
return 0;
}