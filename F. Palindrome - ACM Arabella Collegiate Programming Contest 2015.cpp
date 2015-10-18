#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#define MAX (int)1e9 + (int)7
#define f first
#define s second
using namespace std;
const long long MOD = (int) 1e9 + (int) 7;
vector<int> gs[60000];
bool v[60000];
bool final = true;
string s;
void dfs(int x){
    v[x] = true;
    for(int i = 0;i < gs[x].size();i++){
        if(s[gs[x][i]]!= '?'&&s[x]!= s[gs[x][i]]) final &= false;
        else if(!v[gs[x][i]]){
            s[gs[x][i]] = s[x];
            dfs(gs[x][i]);
        }
    }
}
int main(){
//    freopen("in.txt","r",stdin);
    int n,m,x,y;
  int tc;
  cin >> tc;
  while(tc--){
        final = true;
    cin>> n >> m >> s;
  for(int i = 0;i < n ;i++) v[i] = false,gs[i].clear();
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        x--,y--;
        gs[x].push_back(y);
        gs[y].push_back(x);
    }
    int nn = n-1;
 for(int i = 0;i <= n/2;i++){
    if(i == nn-i) continue;
        gs[i].push_back(nn-i);
        gs[nn-i].push_back(i);

 }

for(int i = 0;i < n;i++)
    if(!v[i]&&s[i]!='?')
        dfs(i);
long long c = 1;
for(int i = 0;i < n;i++)
    if(!v[i]){
        c = (c * 26)%MOD;
        dfs(i);
    }
cout<<(final ? c:0)<<endl;
}
    return 0;
}