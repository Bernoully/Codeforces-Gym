#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define MAX 50009
//#define
const ll  MOD =  (ll)1e9 + (ll)7;

ll fn(int left, int mode);

int n, a, b;
ll dp[MAX][2];

int main()
{
// cout<<MOD<<endl;
    scanf("%d %d %d", &n, &a, &b);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", (fn(n, 0) % MOD + fn(n, 1) % MOD) % MOD);

    return 0;
}

ll fn(int left, int mode)
{
    if(left<0)
        return 0;
    
    if(left == 0)
        return 1;

    ll& ret = dp[left][mode];
    if(ret != -1)
        return ret;

    ret = 0;

    if(mode == 0)
    {
        for(int i = 1; i <= a; i++)
            ret = ret % MOD + fn(left - i, !mode) % MOD, ret = ret % MOD;
    }
    else
    {
        for(int i = 1; i <= b; i++)
            ret = ret % MOD + fn(left - i, !mode) % MOD, ret = ret % MOD;
    }
    ret = ret % MOD;
    return ret ;
}