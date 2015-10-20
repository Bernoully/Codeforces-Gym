#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int main(){
//  freopen("in.txt","r",stdin);
  int tc = 1;
  cin >> tc;
  while(tc--){
int n,m;
int a[1000],b[1000];
int c[1000] = {0};
cin >> n >>m ;
vector<int>ages;
ages.clear();
vector<int>packets;
packets.clear();
int cc[1000] = {0};


for(int i = 0;i <= 100;i++)c[i] = cc[i] = 0;


for(int i = 0;i < n ;i++){
    cin >> a[i];
    if(!c[a[i]])
        ages.push_back(a[i]);
    c[a[i]]++;
}
for(int i = 0;i < m ; i++){
    cin >> b[i];
    if(!cc[b[i]])
        packets.push_back(b[i]);
    cc[b[i]]++;
}

sort(ages.begin(),ages.end());
sort(packets.begin(),packets.end());


bool f = true;
int j = 0;
for(int i = 0 ;i < ages.size();i++){
    while(j < packets.size()&&cc[packets[j]] < c[ages[i]])j++;
    f&= (j < packets.size()&&cc[packets[j]] >= c[ages[i]]);
j++;
}

if(f)
 cout<<"YES\n";
else cout<<"NO\n";
}

    return 0;
}
