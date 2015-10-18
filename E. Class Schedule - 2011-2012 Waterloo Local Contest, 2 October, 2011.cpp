#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX 1009

int fn(int grp, int curr);

int enr[MAX][MAX], dist[MAX][MAX], dp[MAX][MAX];
int n_grp, n_lessons, l;
const int inf = 99999999;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d %d", &n_grp, &n_lessons, &l);
        for(int i = 0; i < n_grp; i++)
            for(int j = 0; j < n_lessons; j++)
            {
                int x, y;
                scanf("%d %d", &x, &y);
                dist[i][j] = x;
                enr[i][j] = y;
            }
        int ans = inf;
        for(int i = 0; i < n_lessons; i++)
            ans = min(ans, fn(0, i) + dist[0][i]);
        printf("%d\n", ans);
    }
    return 0;
}

int fn(int grp, int curr)
{
    if(grp == n_grp - 1)
        return enr[grp][curr] + abs(l - dist[grp][curr]);

    int& ret = dp[grp][curr];
    if(ret != -1)
        return ret;

    ret = inf;
    int tmp = enr[grp][curr];

    for(int i = 0; i < n_lessons; i++)
        ret = min(ret, tmp + fn(grp + 1, i) + abs(dist[grp][curr] - dist[grp + 1][i]));

    return ret;
}