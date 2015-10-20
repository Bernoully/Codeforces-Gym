#include <bits/stdc++.h>
#define f first
#define s second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
using namespace std;

int main(){
//      freopen("in.txt","r",stdin);
  int tc = 1;
  cin >> tc;
 while(tc--){
int n,s;
    cin >> n >> s;
int a[20];
for(int i = 0;i < n;i++) cin >> a[i];
sort(a,a+n);

    unsigned int xss = pow(2, n);
int mx = 0;
for(int i = 1;i <= xss;i++){
    vector<int>money;
    int c = 0;
    for(int j = 0;j < n ;j++)
        if(i&(1<<j)){
            money.pb(a[j]);
            c+= a[j];
        }
        if(c == s) mx = max(mx,(int)money.size());
        else if(c > s){
            c = s;
            bool f = false;
            for(int k = money.size()-1;k >= 0;k--){
                c -= money[k];
                f|=(c <= 0 && k != 0);
            }
            if(!f)  mx = max(mx,(int)money.size());
        }
}
cout<<mx<<endl;
}
    return 0;
}
