#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define f first
#define s second
#define pb push_back
using namespace std;
long long  dist[200000];
bool vs[200000];
pair<int,int>p;
vector<pair<int,int> >gs[200000];
int n;
void dfs(int v){
    vs[v] = true;
    for(int i=0; i<(int)gs[v].size(); i++){
         int u = gs[v][i].f, cost = dist[v] + gs[v][i].s;
        if(!vs[u]&&u!=n+1){
            dist[u] = cost;
            dfs(u);
        }
    }
}

int main(){
//    freopen("in.txt","r",stdin);
    	std::ios::sync_with_stdio(false);
cin >> n;
int x,y,z;
for(int i = 0;i <= n ;i++){
    cin >> x;
    p = {n+1,x};
    gs[i].pb(p);
    p = {i,x};
    gs[n+1].pb(p);
    dist[i] = 0LL;
    vs[i] = false;
}
long long  c = 0;
for(int i = 0;i < n ;i++){
    cin >> x >> y >> z;
    p = {y,z};
    gs[x].pb(p);
    p = {x,z};
    gs[y].pb(p);
    c+=z;
}
dfs(0);
    long long mn = (long long)1<<62;
  for(int i = 0;i <= n;i++)
    mn = min((c*2-dist[i]) +(long long) gs[n+1][i].s,mn);
cout<<mn<<endl;
     return 0;
}
