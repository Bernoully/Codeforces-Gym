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
    int n;
    bool a[200] = {false};
    string s;
    cin >> n >> s;
for(int i = 0;i < n ;i++){
    if(s[i] == '*'){
        a[i] = true;
        if(i+1 < n) a[i+1] = true;
        if(i-1 >= 0) a[i-1] = true;
    }
}

vector<int> blocks;
for(int i = 0;i < n;i++)
    if(!a[i]) blocks.pb(i);
int c = 0;
for(int i = 0;i < blocks.size();i++)
    if(!a[blocks[i]]){
        c++;
        a[blocks[i]] = true;
            if(blocks[i]+1 < n) a[blocks[i]+1] = true;
        if(blocks[i]+2 < n) a[blocks[i]+2] = true;  
    }
cout<<c<<endl;
}
    return 0;
}
