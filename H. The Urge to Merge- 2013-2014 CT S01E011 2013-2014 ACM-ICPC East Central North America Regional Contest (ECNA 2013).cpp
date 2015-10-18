#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 1009
ll fn(int i, int x, int y, int z);

ll a[5][MAX], dp[MAX][2][2][2];
int n, cases = 1;

int main()
{
    while(true)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < n; j++)
                scanf("%lld", &a[i][j]);

        printf("Case %d: %lld\n", cases++, fn(0, 0, 0, 0));
    }
    return 0;
}

ll fn(int i, int x, int y, int z)
{
    ///0 not taken
    ///1 taken
    if(i == n)
        return 0;
    ll& ret = dp[i][x][y][z];
    if(ret != -1)
        return ret;
    ret = 0;
    ll tmp;
    if(!x && !y)
    {
        tmp = a[0][i] * a[1][i];
        if(!z && i + 1 < n)
            ret = max(ret, a[2][i] * a[2][i + 1] + tmp + fn(i + 1, 0, 0, 1));

        ret = max(ret, tmp + fn(i + 1, 0, 0, 0));
    }

    if(!z && !y)
    {
        tmp = a[2][i] * a[1][i];
        if(!x && i + 1 < n)
            ret = max(ret, a[0][i] * a[0][i + 1] + tmp + fn(i + 1, 1, 0, 0));

        ret = max(ret, tmp + fn(i + 1, 0, 0, 0));
    }


    ///0 0 0
    ret = max(ret, fn(i + 1, 0, 0, 0));

    ///1 1 1
    if(!x && !y && !z && i + 1 < n)
    {
        int tmp = a[0][i] * a[0][i + 1] + a[1][i] * a[1][i + 1] + a[2][i] * a[2][i + 1];
        ret = max(ret, tmp + fn(i + 1, 1, 1, 1));
    }

    ///1 0 0
    if(!x && i + 1 < n)
        ret = max(ret, a[0][i] * a[0][i + 1] + fn(i + 1, 1, 0, 0));

    ///0 1 0
    if(!y && i + 1 < n)
        ret = max(ret, a[1][i] * a[1][i + 1] + fn(i + 1, 0, 1, 0));

    ///0 0 1
    if(!z && i + 1 < n)
        ret = max(ret, a[2][i] * a[2][i + 1] + fn(i + 1, 0, 0, 1));

    /// 1 1 0
    if(!x && !y && i + 1 < n)
        ret = max(ret, a[0][i] * a[0][i + 1] + a[1][i] * a[1][i + 1] + fn(i + 1, 1, 1, 0));

    /// 0 1 1
    if(!z && !y && i + 1 < n)
        ret = max(ret, a[2][i] * a[2][i + 1] + a[1][i] * a[1][i + 1] + fn(i + 1, 0, 1, 1));

    /// 1 0 1
    if(!z && !x && i + 1 < n)
        ret = max(ret, a[2][i] * a[2][i + 1] + a[0][i] * a[0][i + 1] + fn(i + 1, 1, 0, 1));

    return ret;
}