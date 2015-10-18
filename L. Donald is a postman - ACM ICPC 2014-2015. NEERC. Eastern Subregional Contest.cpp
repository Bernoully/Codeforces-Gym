#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
mp['A'] = 1;
mp['P'] = 1;
mp['O'] = 1;
mp['R'] = 1;

mp['B'] = 2;
mp['M'] = 2;
mp['S'] = 2;

mp['D'] = 3;
mp['J'] = 3;
mp['G'] = 3;
mp['K'] = 3;
mp['T'] = 3;
mp['W'] = 3;

int old = 1,x,c = 0,n;
cin >> n;
string s;
for(int i = 0;i < n ;i++){
    cin >> s;
    x = mp[s[0]];
    c+= abs(x - old);
    old = x;
}
cout<<c<<endl;
return 0;
}