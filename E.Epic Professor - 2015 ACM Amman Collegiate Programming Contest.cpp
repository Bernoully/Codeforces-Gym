#include <bits/stdc++.h>
using namespace std;
int main(){
//freopen("in.txt","r",stdin);
  int tc = 1;
  cin >> tc;
  while(tc--){
 int n,a[200];
 cin >> n;
 int mn = 100;
 for(int i = 0;i < n ;i++) cin >> a[i],mn = min(mn,100-a[i]);
int c = 0;
for(int i = 0;i < n;i++)
c+=(a[i]+mn >= 50);
cout<<c<<endl;
  } 
    return 0;
}
