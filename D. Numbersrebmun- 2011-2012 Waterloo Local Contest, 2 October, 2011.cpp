#include <iostream>
#include <map>
using namespace std;
map <char,int> mp;
int main(){
 mp['T'] = 8;
  mp['t'] = 8;mp['U'] = 8;mp['u'] = 8;mp['V'] = 8;mp['v'] = 8;
  mp['W'] = 9,mp['w'] = 9,mp['X'] = 9,mp['x'] = 9,mp['Y'] = 9,mp['y'] = 9,mp['Z'] = 9,mp['z'] = 9;
int idx = 2;
char c,c2;
  for(c = 'A',c2 = 'a'; c <= 'z'&&idx <= 6;){
    for(int i = 0;i < 3;i++,c++,c2++)
        mp[c] = idx,mp[c2] = idx;
    idx++;
  }

  for(; c <= 'z'&&idx <= 7;){
    for(int i = 0;i < 4;i++,c++,c2++)
        mp[c] = idx,mp[c2] = idx;
    idx++;
  }
int tc;
cin >> tc;
while(tc--){
  string s,s2;
  cin >> s;
  bool f = true;
  for(int i = 0, j = s.size()-1;i < s.size()/2;i++,j--){
    f&= (mp[s[i]] == mp[s[j]]);
  }
  cout<<(f ? "YES":"NO")<<endl;
}
    return 0;
}