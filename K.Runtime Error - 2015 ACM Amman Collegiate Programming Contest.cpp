#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
  int tc = 1;
  cin >> tc;
  while(tc--){
int h[3000000] = {false};
int n,k,a[3000000];
cin >> n >> k;
int xx;
for(int i = 0;i < n;i++){
 cin >> a[i],h[a[i]]++;
if(a[i]) xx = a[i];
}
if(!k){
    if(h[0] == 1) cout<<0<<" "<<xx<<endl;
    else if(h[0] > 1) cout<<0<<" "<<0<<endl;
    else cout<<-1<<endl;
    continue;
} 
int mn = 1<<30;
for(int i = 0;i < n;i++){
    if(a[i]&&!(k%a[i]) && h[k/a[i]]){
        if(k/a[i] == a[i]){
            if(h[a[i]] <= 1) continue;
        }
if(min(a[i],k/a[i]) < mn) mn = min(a[i],k/a[i]);

}
    
}
if(mn == 1<<30)
cout<<-1<<endl;
else cout<<min(mn,k/mn)<<" "<<max(mn,k/mn)<<endl;

}

    return 0;
}
