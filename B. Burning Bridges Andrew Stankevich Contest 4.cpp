#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <sstream>
#include <algorithm>
#define id first
#define count second
using namespace std;
int timer = 0;
int dfslow[200000],dfsnum[200000],parent[200000];
vector<int>bridgess;
vector<int> gs[200000];
map<pair<int,int>,int>mps;
map<int,int>::iterator it;
pair<int,int> p;
bool h[200000];

void bridges(int x){
	dfsnum[x] = dfslow[x] = timer++;
	for(int i = 0;i < gs[x].size();i++){
		if(dfsnum[gs[x][i]] == -1){
			parent[gs[x][i]] = x;
			bridges(gs[x][i]);
			if(dfslow[gs[x][i]] > dfsnum[x]){
               p = {min(x,gs[x][i]),max(x,gs[x][i])};
			int z = mps[p];
			if(!h[z]&&z)
				bridgess.push_back(mps[p]);
			}
			dfslow[x] = min(dfslow[x],dfslow[gs[x][i]]);
		}else if(parent[x]!= gs[x][i])
		dfslow[x] = min(dfslow[x],dfsnum[gs[x][i]]);
	}
}

int main(){
		std::ios::sync_with_stdio(false);
	freopen("bridges.in","r",stdin);
	freopen("bridges.out","w",stdout);
int n,m,index = 0;
cin >> n >> m;
for(int i = 0;i<=n;i++)
	dfsnum[i] = -1,dfslow[i] = 0,parent[i]=i;
for(int i = 0;i<=m;i++) h[i] = false;

int x,y,z;
string s;
for(int i = 1;i <= m;i++){
	cin >> x >> y;
	gs[x].push_back(y);
	gs[y].push_back(x);
p = {min(x,y),max(x,y)};
int zz = mps[p];
if(!mps[p])
    mps[p] = i;
else
h[zz] = true;
}
	bridges(1);
sort(bridgess.begin(),bridgess.end());
cout<<bridgess.size()<<endl;
for(int i = 0;i < bridgess.size();i++)
	cout<<bridgess[i]<<' ';cout<<'\n';
    return 0;
}
