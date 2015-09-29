#include <iostream>
#include <algorithm>
using namespace std;

int main(){
int tc;
cin >> tc;
while(tc--){
 int x,y,z;
cin >> x >> y >> z;
cout<<((x+y+z==180&&x&&y&&z) ? "YES":"NO")<<endl;
}
return 0;
}