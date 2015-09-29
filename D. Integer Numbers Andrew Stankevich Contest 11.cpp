#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int h[60000];
int mx,mxidx;
int main(){
//	freopen("in.txt","r",stdin);
	freopen("integer.in","r",stdin);
	freopen("integer.out","w",stdout);
	int n;
	int a[60000];
	cin >> n;
	int index = 1,z;
	for(int i = 0;i < n;i++){
	 cin >> a[i];
	 if(!mp[a[i] - i]) mp[a[i] - i] = index++;
	 z = mp[a[i] - i];
	 h[z]++;
	 if(h[z] > mx)
	 	mx = h[z],mxidx = a[i] - i;
	}
	int c = 0;
for(int j = 0,i = mxidx ; j < n ;j++,i++)
	c+= (a[j]!=i);
cout<<c<<endl;
for(int j = 0,i = mxidx;j < n;j++,i++)
	cout<<i<<' ';
cout<<'\n';

    return 0;
}
