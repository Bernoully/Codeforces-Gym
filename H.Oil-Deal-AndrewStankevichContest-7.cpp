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
int parent[60000];
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

bool srt(int x,int y){
	return x < y;
}
void unionu(int x,int y){
	parent[finds(x)] = finds(y);
}



int main(){
		std::ios::sync_with_stdio(false);
	freopen("oil.in","r",stdin);
	freopen("oil.out","w",stdout);
	cin >> n >> m >> t;
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
vector<pair<int,int> >offf;
for(int i = gs.size()-1;i >= 0;i--){
	p = gs[i].s;
	if(!check(p.f,p.s)){
		unionu(p.f,p.s);
	}else{
		p = {gs[i].ff,gs[i].fs};
		offf.push_back(p);
	}
}
int c = 0;
vector<int> ffs;
for(int i = offf.size() - 1; i >= 0&& t - offf[i].f >= 0;i--)
	t-=offf[i].f,ffs.push_back(offf[i].s+1);

cout<<ffs.size()<<endl;
sort(ffs.begin(),ffs.end());
if(ffs.size()) cout<<ffs[0];
for(int i = 1;i < ffs.size();i++)
	cout<<" "<<ffs[i];cout<<endl;
	return 0;
}