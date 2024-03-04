#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a)) // int:0/-1, bool, char

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 0 )
#define mxn           100010

map< pair<int,int> , int > mp, mp2;

void solve(int tc)
{
    int n;
    sfi(n);

    int a[n], b[n];
    rep(i, 0, n) sfi(a[i]);
    rep(i, 0, n) sfi(b[i]);

    int any = 0;
    rep(i, 0, n){

        if(a[i]==0){
            if(b[i]==0) any++;
            continue;
        }

        int g = __gcd(abs(b[i]), abs(a[i]));

        if(b[i]>=0 and a[i]>=0){
            b[i] /= g;
            a[i] /= g;
            mp[make_pair(b[i], a[i])]++;
        }
        else if(b[i]<0 and a[i]<0){
            b[i] = -b[i];
            a[i] = -a[i];

            b[i] /= g;
            a[i] /= g;
            mp[make_pair(b[i], a[i])]++;
        }
        else if(b[i]<0 and a[i]>=0){
            b[i] /= g;
            a[i] /= g;
            mp[make_pair(b[i], a[i])]++;
        }
        else if(b[i]>=0 and a[i]<0){
            b[i] = -b[i];
            a[i] = -a[i];

            b[i] /= g;
            a[i] /= g;
            mp[make_pair(b[i], a[i])]++;
        }
    }

    int ans = 0;
    repit(it, mp){
        debug cout<<"check: "<<it->first.first<<sp<<it->first.second<<sp<<it->second<<endl;
        ans = max(ans, it->second);
    }

    ans += any;

    pfin(ans);
}


int32_t main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0); cin.tie(0);

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

/*
3
0 0 1
0 0 0
*/


// int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1}; //4 Direction
// int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
// int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
// int dx[]={2,1,-1,-2,-1,1}; int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

