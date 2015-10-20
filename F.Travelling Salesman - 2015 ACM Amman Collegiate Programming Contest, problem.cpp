#include <bits/stdc++.h>
#define f first
#define s second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
using namespace std;
typedef pair<pair<int,int>,pair<int,int> > dpair;
int n,m;
long long t;
int parent[600000];
vector<dpair> gs;
pair<int,int> p,p2;
dpair pp;

void start(){
    for(int i = 0;i <= n ;i++) parent[i] = i;
}

int  finds(int x){
    return parent[x] == x ? x : parent[x] = finds(parent[x]);
}

bool check(int x,int y){
    return finds(x) == finds(y);
}

void unionu(int x,int y){
    parent[finds(x)] = finds(y);
}



int main(){
        std::ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);
  int tc = 1;
  cin >> tc;
  while(tc--){
    gs.clear();
    cin >> n >> m ;
int x,y,z;
for(int i = 0;i < m ;i++){
    cin >> x >> y >> z;
    p = {x,y};
    p2 = {z,i};
    pp = {p2,p};
 gs.push_back(pp);
}
sort(gs.begin(),gs.end());
start();
int mx = 0;
vector<pair<int,int> >offf;
for(int i = 0;i < gs.size();i++){
    p = gs[i].s;
    if(!check(p.f,p.s)){
        unionu(p.f,p.s);
               mx = max(mx,gs[i].f.f);
    }
}
cout<<mx<<endl;
}

    return 0;
}
