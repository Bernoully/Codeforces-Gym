#include <iostream>
#include <algorithm>
using namespace std;
const int  dx[] = {0,0,0,3,3,3,6,6,6};
const int dy[] = {0,3,6,0,3,6,0,3,6};
int main(){
int tc;
 cin >> tc ;
while(tc--){
    int a[10][10];
string s;
bool finalz = true;
for(int i = 0;i < 9;i++){
  cin >>s ;
    for(int j = 0; j < 9;j++)
    a[i][j] = s[j]-'0';
}
       int c = 0,c2 = 0;
for(int i = 0;i <9;i++){
        c = c2 = 0;
    for(int j = 0;j < 9;j++)
    c+=a[i][j],c2+=a[j][i];

finalz&= (c == 45 && c2 == 45);
}

int cs[10] = {0};
for(int i = 0;i < 3;i++)
    for(int j = 0;j < 3;j++){
        for(int k = 0;k < 9;k++){
                cs[k] += a[i+dx[k]][j+dy[k]];
        }
    }

for(int i = 0;i < 9;i++){
    finalz&=(cs[i] == 45);
}
cout<<(finalz ? "Valid":"Invalid")<<endl;
}
return 0;
}