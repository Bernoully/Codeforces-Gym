#include <bits/stdc++.h>
using namespace std;
int main(){
//freopen("in.txt","r",stdin);
  int tc = 1;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    string s,w;
    int m,p;
    int mnp = 1<<30,mx = 0;
    for(int i = 0;i < n ;i++){
    cin >> s >> m >> p;
    if(m > mx){
        mx = m;
        mnp = p;
        w = s;
    }else if(m == mx && p < mnp){
        mnp = p;
        w = s;
    }

  }
cout<<w<<endl;
  } 
    return 0;
}
