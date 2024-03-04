#include<bits/stdc++.h>
using namespace std;
#define MX 1000000
long long phi[MX+1];

void computeTotient(int n)
{

    for (int i=1; i<=n; i++)
        phi[i] = i;
    for (int p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;
            for (int i = 2*p; i<=n; i += p)
            {
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
}

int main()
{
    computeTotient(MX);

    int tc, a;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++){
        scanf("%d", &a);
        printf("%lld\n", phi[a]);
    }
    return 0;
}

