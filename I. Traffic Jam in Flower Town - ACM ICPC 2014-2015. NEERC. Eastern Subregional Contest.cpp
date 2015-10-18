#include <bits/stdc++.h>
using namespace std;
int main(){
string s,s2;
cin >> s >> s2;
int i = 0,j = 0;
long long  c = 0;

while(i < s.size()&&j < s2.size()){
    if(s[i]!='L'&&s2[j]!= 'L') i++,j++,c++;
else  if(s[i] =='L'&&s2[j] == 'L') i++,j++,c++;
else if(s[i] !='L'&&s2[j] == 'L'){
    while(s[i] !='L'&&i<s.size())i++,c++;
    c++;
    j++;
    if(i < s.size()&&s[i] == 'L') i++;
}else if(s[i] == 'L'&&s2[j] !='L'){
    while(s2[j] !='L'&&j<s2.size())j++,c++;
    c++;
    i++;
    if(j <  s2.size()&&s2[j] == 'L')j++;
}
}
while(i < s.size())i++,c++;
while(j < s2.size())j++,c++;
cout<<c<<endl;
return 0;
}