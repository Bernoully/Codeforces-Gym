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

void fn(int x);

int h1[MAX], h2[MAX], n1, n2, x, m, cases = 1;

int main()
{
    while(true)
    {
        memset(h2, -1, sizeof(h2));
        memset(h1, -1, sizeof(h1));

        scanf("%d %d %d", &n1, &n2, &m);
        if(n1 + n2 + m == 0)
            break;

        for(int i = 0; i < m; i++)
            scanf("%d", &x), fn(x);
        int f = 0;
        printf("Case %d:\n", cases++);
        for(int i = 0; i <= n1; i++)
        {
            if(h1[i] != -1)
            {
                if(f == 0)
                    printf("Table 1\n");

                    f = 1;
                printf("%d:%d\n", i, h1[i]);
            }
        }

        f = 0;
        for(int i = 0; i <= n2; i++)
        {
            if(h2[i] != -1)
            {
                if(f == 0)
                    printf("Table 2\n");
                    f = 1;
                printf("%d:%d\n", i, h2[i]);
            }

        }


    }


    return 0;
}


void fn(int x)
{
    int f = 0;
    while(true)
    {
        if(f == 0)
        {
            if(h1[x % n1] == -1)
            {
                h1[x % n1] = x;
                return;
            }
            swap(x, h1[x % n1]);
            f = !f;
        }
        else
        {
            if(h2[x % n2] == -1)
            {
                h2[x % n2] = x;
                return;
            }
            swap(x, h2[x % n2]);
            f = !f;
        }
    }

}