#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#define MAX (int)1e9 + (int)7
#define f first
#define s second
using namespace std;
int a[10005],n;
int b[10035]; 
int main(){
int tc;
    cin >> tc;
    while(tc--){
cin >> n;
long long c = 0;
 for(int i = 0;i < 10035;i++) b[i] = 0;
for(int i = 0;i < n ;i++){
    cin >> a[i];
    c+=b[a[i]];
     for (int j=max(0,a[i]-31);j<=min(a[i]+31,10000);j++)
        b[j]++;

    }
    cout<<c<<endl;
    }
    return 0;
}