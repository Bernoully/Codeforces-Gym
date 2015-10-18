#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int main(){
int n;
int c = 0,d = 0;
pair<int,int> a[2000],b[2000],p;
cin >> n;
int x;
for(int i = 0;i < n ;i++){
    cin >> x;
    p = {x,i+1};
    a[i] = p;
    c+=x;
}
for(int i = 0;i < n ;i++){
    cin >> x;
       p = {x,i+1};
    b[i] = p;
    d+=x;
}

sort(a,a+n);
sort(b,b+n);
if(d > c){
    for(int i = 0,j = n-1;i < n;i++,j--)
    cout<<a[j].s<<" "<<b[i].s<<"\n";
}else
for(int i = 0,j = n-1;i < n;i++,j--)
    cout<<a[i].s<<" "<<b[j].s<<"\n";//<<a[i].f<<" "<<b[i].f<<endl;
    return 0;
}