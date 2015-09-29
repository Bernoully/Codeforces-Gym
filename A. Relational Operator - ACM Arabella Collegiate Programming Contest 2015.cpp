#include <iostream>

using namespace std;

int main(){
    int tc;
   int x,y;
string s,s2;
char c,c2;
cin >> tc;
while(tc--){
cin >> x >>s>>y;
int i = 0;
if(s == ">") cout<<(x>y? "true":"false")<<endl;
else if(s== ">=") cout<<(x>=y ? "true":"false")<<endl;
else if(s== "<=") cout<<(x<=y? "true":"false")<<endl;
    else if(s== "<") cout<<(x<y? "true":"false")<<endl;
else if(s== "==") cout<<(x==y? "true":"false")<<endl;
else if(s== "!=") cout<<(x!=y? "true":"false")<<endl;
}
    return 0;
}